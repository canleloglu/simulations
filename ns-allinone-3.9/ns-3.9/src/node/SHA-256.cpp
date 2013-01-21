//
// SHA-256.cpp: implementation of the CSHA256 class.
//
// Created by Mark Muir 2005/1/5
// Copyright 2005 Mark Muir. All rights reserved.
//
// Concrete sub-class of CHash; object to perform hashing based on the National
// Standards Agency (NSA) SHA-256 (Secure Hash Algorithm - member of the SHA-2
// family) algorithm. The 256-bit SHA-256 hash (digest) for files or arbitrary
// text strings is returned as a NULL-terminated string containing the
// hexadecimal represtentation. This implementation conforms to FIPS-180-2.

#include "SHA-256.h"
#include <string.h>


//-----------------------------------------
// SHA-256 Algorithm Transformation Macros
//-----------------------------------------

// Get_uint32()
// Constructs a 32-bit big-endian value from the array of 8-bit values
// given by b, starting at index i. The result is stored in n.
#define Get_uint32(n, b, i)					\
{											\
	(n) = ((uint32)(b)[(i)    ] << 24)		\
		| ((uint32)(b)[(i) + 1] << 16)		\
		| ((uint32)(b)[(i) + 2] <<  8)		\
		| ((uint32)(b)[(i) + 3]      );		\
}

// Put_uint32()
// Decodes the 32-bit big-endian value given as n into the array of
// 8-bit values given by b, starting at index i.
#define Put_uint32(n, b, i)					\
{											\
	(b)[(i)    ] = (uint8)((n) >> 24);		\
	(b)[(i) + 1] = (uint8)((n) >> 16);		\
	(b)[(i) + 2] = (uint8)((n) >>  8);		\
	(b)[(i) + 3] = (uint8)((n)      );		\
}

// RotateRight()
// Rotates the 32-bit unsigned integer x right by n bits.
#define RotateRight(x, n)	((x >> n) | (x << (32 - n)))

// State manipulation macros - one for each round.
#define S0(x)	(RotateRight(x,  7) ^ RotateRight(x, 18) ^ (x >>  3))
#define S1(x)	(RotateRight(x, 17) ^ RotateRight(x, 19) ^ (x >> 10))
#define S2(x)	(RotateRight(x,  2) ^ RotateRight(x, 13) ^ RotateRight(x, 22))
#define S3(x)	(RotateRight(x,  6) ^ RotateRight(x, 11) ^ RotateRight(x, 25))

// Transformation macros
#define F0(x, y, z)		((x & y) | (z & (x | y)))
#define F1(x, y, z)		(z ^ (x & (y ^ z)))

// R()
// Used to expand (partially in-place) the 16 32-bit words in array
// x[] into 60 32-bit words. The index of the word to be generated
// is given by the position parameter t.
#define R(t)							\
(										\
	x[t] = S1(x[t- 2]) + x[t- 7]		\
		 + S0(x[t-15]) + x[t-16]		\
)

// P()
// SHA-256 transformation used in each of the four rounds. The two 32-bit
// unsigned integer temporary variables temp1 and temp2 must exist at the
// place of call.
#define P(a, b, c, d, e, f, g, h, x, K)			\
{												\
	temp1 = h + S3(e) + F1(e, f, g) + K + x;	\
	temp2 = S2(a) + F0(a, b, c);				\
	d += temp1; h = temp1 + temp2;				\
}


//---------------------------------
// Instance Method Implementations
//---------------------------------

// CalculateHash()
// Returns the text string containing the SHA-256 digest for the given text message.
const char* CSHA256::CalculateHash(const char *szText)
{
	// Create the digest for the given text string
	Start();
	Update((unsigned char*)szText, strlen(szText));
	Finish();
	// Return the hex digest string
	return m_szDigest;
}

// CalculateHash()
// Returns a text string containing the SHA-256 digest for the given file. The file
// is read from the beginning to until EOF is reached. The function prints to
// stdout the size of the file, followed by a frequently updated progress bar.
// The file size text is padded with trailing white space to make it at least
// iColumnWidth characters wide, after which the progress bar is drawn. Always at
// least one space follows the text. Upon completion, the progress bar is erased,
// leaving the insertion point at the end of the white space, ready for the caller
// to print some terminating text (e.g. the hash string). If iColumnWidth is 0
// (default), the only white space generated is the final ' '.
const char* CSHA256::CalculateHash(FILE *fin, int iColumnWidth)
{
	unsigned long   ulFileSize, ulBytes;
	int				iNumChars = 0;
	
	// Determine the size of the file and move to the beginning
	fseek(fin, 0, SEEK_END);
	ulFileSize = ftell(fin);
	fseek(fin, 0, SEEK_SET);
	{
		int i, iCount;
		char szSize[64];
		FileSizeToText(ulFileSize, szSize, 0);
		printf("%s%n", szSize, &iCount);
		for(i=iCount; i<iColumnWidth-1; i++) printf(" ");
		printf(" ");
		fflush(stdout);
	}
	
	// Create the digest for the specified file
	Start();
	ulBytes = 0;
	while(1)
	{
		int i, iRead;
		
		// Clear the progress bar
		for(i=0; i<iNumChars; i++) printf("\b \b");
		
		// Read the next block
		iRead = fread(m_ucBuffer, sizeof(unsigned char), BLOCK_SIZE, fin);
		ulBytes += iRead;
		
		// Check for end condition
		if(!iRead) break;
		
		// Update the state for this block
		Update(m_ucBuffer, iRead);
		
		// Update progress message
		double fComplete = (double)ulBytes/(double)ulFileSize;
		for(i=0; i<=(int)(PROGRESS_BAR_LENGTH*fComplete-0.5); i++)
			printf("#");
		for(; i<PROGRESS_BAR_LENGTH; i++)
			printf("-");
		printf(" %d%%%n", (int)(100*fComplete), &iNumChars);
		iNumChars += PROGRESS_BAR_LENGTH;
		fflush(stdout);
		// N.B. stdout is used for the progress bar instead of stderr becuase
		// the buffering of the output stream allows the message to only be drawn
		// following fflush(). stderr is not buffered, so the progress bar appears
		// to flicker.
	}
	Finish();
	
	// Return the hex digest string
	return m_szDigest;
}

// Start()
// Resets the state and counters, ready to start the next digest.
void CSHA256::Start()
{
	// Reset the count of the number of data bits transformed
	m_ulTotal[0] = 0;
	m_ulTotal[1] = 0;
	
	// Initialise the state variables
	m_ulState[0] = 0x6a09e667;
	m_ulState[1] = 0xbb67ae85;
	m_ulState[2] = 0x3c6ef372;
	m_ulState[3] = 0xa54ff53a;
	m_ulState[4] = 0x510e527f;
	m_ulState[5] = 0x9b05688c;
	m_ulState[6] = 0x1f83d9ab;
	m_ulState[7] = 0x5be0cd19;
}

// Transform()
// Transform the next (512-bit) block of data.
void CSHA256::Transform(uint8 data[64])
{
	uint32 temp1, temp2, x[64], a, b, c, d, e, f, g, h;
	
	// Break the block into sixteen 32-bit big-endian words 
	Get_uint32(x[ 0], data,  0);
	Get_uint32(x[ 1], data,  4);
	Get_uint32(x[ 2], data,  8);
	Get_uint32(x[ 3], data, 12);
	Get_uint32(x[ 4], data, 16);
	Get_uint32(x[ 5], data, 20);
	Get_uint32(x[ 6], data, 24);
	Get_uint32(x[ 7], data, 28);
	Get_uint32(x[ 8], data, 32);
	Get_uint32(x[ 9], data, 36);
	Get_uint32(x[10], data, 40);
	Get_uint32(x[11], data, 44);
	Get_uint32(x[12], data, 48);
	Get_uint32(x[13], data, 52);
	Get_uint32(x[14], data, 56);
	Get_uint32(x[15], data, 60);
	
	// Initialise the hash value for this block
	a = m_ulState[0];
	b = m_ulState[1];
	c = m_ulState[2];
	d = m_ulState[3];
	e = m_ulState[4];
	f = m_ulState[5];
	g = m_ulState[6];
	h = m_ulState[7];

	// Perform the transformations, expanding the sixteen 32-bit
	// words into sixty-four 32-bit words.
	P(a, b, c, d, e, f, g, h, x[ 0], 0x428a2f98);
	P(h, a, b, c, d, e, f, g, x[ 1], 0x71374491);
	P(g, h, a, b, c, d, e, f, x[ 2], 0xb5c0fbcf);
	P(f, g, h, a, b, c, d, e, x[ 3], 0xe9b5dba5);
	P(e, f, g, h, a, b, c, d, x[ 4], 0x3956c25b);
	P(d, e, f, g, h, a, b, c, x[ 5], 0x59f111f1);
	P(c, d, e, f, g, h, a, b, x[ 6], 0x923f82a4);
	P(b, c, d, e, f, g, h, a, x[ 7], 0xab1c5ed5);
	P(a, b, c, d, e, f, g, h, x[ 8], 0xd807aa98);
	P(h, a, b, c, d, e, f, g, x[ 9], 0x12835b01);
	P(g, h, a, b, c, d, e, f, x[10], 0x243185be);
	P(f, g, h, a, b, c, d, e, x[11], 0x550c7dc3);
	P(e, f, g, h, a, b, c, d, x[12], 0x72be5d74);
	P(d, e, f, g, h, a, b, c, x[13], 0x80deb1fe);
	P(c, d, e, f, g, h, a, b, x[14], 0x9bdc06a7);
	P(b, c, d, e, f, g, h, a, x[15], 0xc19bf174);
	P(a, b, c, d, e, f, g, h, R(16), 0xe49b69c1);
	P(h, a, b, c, d, e, f, g, R(17), 0xefbe4786);
	P(g, h, a, b, c, d, e, f, R(18), 0x0fc19dc6);
	P(f, g, h, a, b, c, d, e, R(19), 0x240ca1cc);
	P(e, f, g, h, a, b, c, d, R(20), 0x2de92c6f);
	P(d, e, f, g, h, a, b, c, R(21), 0x4a7484aa);
	P(c, d, e, f, g, h, a, b, R(22), 0x5cb0a9dc);
	P(b, c, d, e, f, g, h, a, R(23), 0x76f988da);
	P(a, b, c, d, e, f, g, h, R(24), 0x983e5152);
	P(h, a, b, c, d, e, f, g, R(25), 0xa831c66d);
	P(g, h, a, b, c, d, e, f, R(26), 0xb00327c8);
	P(f, g, h, a, b, c, d, e, R(27), 0xbf597fc7);
	P(e, f, g, h, a, b, c, d, R(28), 0xc6e00bf3);
	P(d, e, f, g, h, a, b, c, R(29), 0xd5a79147);
	P(c, d, e, f, g, h, a, b, R(30), 0x06ca6351);
	P(b, c, d, e, f, g, h, a, R(31), 0x14292967);
	P(a, b, c, d, e, f, g, h, R(32), 0x27b70a85);
	P(h, a, b, c, d, e, f, g, R(33), 0x2e1b2138);
	P(g, h, a, b, c, d, e, f, R(34), 0x4d2c6dfc);
	P(f, g, h, a, b, c, d, e, R(35), 0x53380d13);
	P(e, f, g, h, a, b, c, d, R(36), 0x650a7354);
	P(d, e, f, g, h, a, b, c, R(37), 0x766a0abb);
	P(c, d, e, f, g, h, a, b, R(38), 0x81c2c92e);
	P(b, c, d, e, f, g, h, a, R(39), 0x92722c85);
	P(a, b, c, d, e, f, g, h, R(40), 0xa2bfe8a1);
	P(h, a, b, c, d, e, f, g, R(41), 0xa81a664b);
	P(g, h, a, b, c, d, e, f, R(42), 0xc24b8b70);
	P(f, g, h, a, b, c, d, e, R(43), 0xc76c51a3);
	P(e, f, g, h, a, b, c, d, R(44), 0xd192e819);
	P(d, e, f, g, h, a, b, c, R(45), 0xd6990624);
	P(c, d, e, f, g, h, a, b, R(46), 0xf40e3585);
	P(b, c, d, e, f, g, h, a, R(47), 0x106aa070);
	P(a, b, c, d, e, f, g, h, R(48), 0x19a4c116);
	P(h, a, b, c, d, e, f, g, R(49), 0x1e376c08);
	P(g, h, a, b, c, d, e, f, R(50), 0x2748774c);
	P(f, g, h, a, b, c, d, e, R(51), 0x34b0bcb5);
	P(e, f, g, h, a, b, c, d, R(52), 0x391c0cb3);
	P(d, e, f, g, h, a, b, c, R(53), 0x4ed8aa4a);
	P(c, d, e, f, g, h, a, b, R(54), 0x5b9cca4f);
	P(b, c, d, e, f, g, h, a, R(55), 0x682e6ff3);
	P(a, b, c, d, e, f, g, h, R(56), 0x748f82ee);
	P(h, a, b, c, d, e, f, g, R(57), 0x78a5636f);
	P(g, h, a, b, c, d, e, f, R(58), 0x84c87814);
	P(f, g, h, a, b, c, d, e, R(59), 0x8cc70208);
	P(e, f, g, h, a, b, c, d, R(60), 0x90befffa);
	P(d, e, f, g, h, a, b, c, R(61), 0xa4506ceb);
	P(c, d, e, f, g, h, a, b, R(62), 0xbef9a3f7);
	P(b, c, d, e, f, g, h, a, R(63), 0xc67178f2);

	// Add this block's hash value to the result so far
	m_ulState[0] += a;
	m_ulState[1] += b;
	m_ulState[2] += c;
	m_ulState[3] += d;
	m_ulState[4] += e;
	m_ulState[5] += f;
	m_ulState[6] += g;
	m_ulState[7] += h;
}

// Update()
// Continues the digest operation with this next arbitrary length of data.
void CSHA256::Update(uint8 *input, uint32 length)
{
	uint32 left, fill;
	
	if(!length) return;
	
	// Calculate the offset in the buffer for where the beginning of
	// the data should be written (number of bytes modulo 64).
	left = m_ulTotal[0] & 0x3f;
	// Calculate how much space will remain in the buffer
	fill = 64 - left;

	// Increment the count of the data bits processed
	m_ulTotal[0] += length;						// Lower 32-bits
	if(m_ulTotal[0] < length) m_ulTotal[1] ++;	// Upper 32-bits

	if(left && length >= fill)
	{
		// There is sufficient data to fill the buffer, so fill the rest
		// of the buffer and transform
		memcpy(m_ucBufferSHA+left, input, fill);
		Transform(m_ucBufferSHA);
		length -= fill;
		input  += fill;
		// Buffer the remaining data
		left = 0;
	}
	
	// Now transform each remaining 64-byte (512-bit) block
	// of input data, bypassing the buffer
	while(length >= 64)
	{
		Transform(input);
		length -= 64;
		input  += 64;
	}
	
	// Buffer any remaining data
	memcpy(m_ucBufferSHA + left, input, length);
}

// Finish()
// Terminates the hashing operation, arriving at the final hash value.
void CSHA256::Finish()
{
	static uint8 padding[64] = { 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	uint32 last, padn;
	uint32 high, low;
	uint8  msglen[8];
	
	// Save the number of bits (before padding)
	high = ( m_ulTotal[0] >> 29 )
		 | ( m_ulTotal[1] <<  3 );
	low  = ( m_ulTotal[0] <<  3 );
	Put_uint32(high, msglen, 0);
	Put_uint32(low,  msglen, 4);

	// Pad so that the last 8 bytes align with the end of a block.
	// These will contain the count of the total number of bits.
	last = m_ulTotal[0] & 0x3f;
	padn = (last < 56)? (56 - last) : (120 - last);
	Update(padding, padn);
	
	// Append the length of the data (number of bits)
	Update(msglen, 8);
	
	// m_ulState now contains the final digest, so construct
	// the hex digest string from the state.
	uint8 digest[4];
	for(int i=0; i<8; i++)
	{
		Put_uint32(m_ulState[i], digest, 0);
		sprintf(m_szDigest+i*8, "%02X%02X%02X%02X",
				digest[0], digest[1], digest[2], digest[3]);
	}
}
