//
// SHA-256.h: interface for the CSHA256 class.
//
// Created by Mark Muir 2005/1/5
// Copyright 2005 Mark Muir. All rights reserved.
//
// Concrete sub-class of CHash; object to perform hashing based on the National
// Standards Agency (NSA) SHA-256 (Secure Hash Algorithm - member of the SHA-2
// family) algorithm. The 256-bit SHA-256 hash (digest) for files or arbitrary
// text strings is returned as a NULL-terminated string containing the
// hexadecimal represtentation. This implementation conforms to FIPS-180-2.

#ifndef __SHA_256_H__INCLUDED__
#define __SHA_256_H__INCLUDED__

#include "Hash.h"

#ifndef uint8
#define uint8 unsigned char
#endif

#ifndef uint32
#define uint32 unsigned long int
#endif

class CSHA256 : public CHash
{
protected:
	uint32 m_ulState[8];		// The state values that are updated to form the digest
	uint32 m_ulTotal[2];		// Count of the number of bits of input data operated on
	uint8  m_ucBufferSHA[64];	// Buffer for the remainder of data passed to Update()
								// N.B. Only complete blocks of 64 bytes can be transformed
	char m_szDigest[65];		// The hex digest/hash string

protected:
	void Start();
	void Transform(uint8 data[64]);
	void Update(uint8 *input, uint32 length);
	void Finish();

public:
	const char* CalculateHash(const char *szText);
	const char* CalculateHash(FILE *fin, int iColumnWidth = 0);
	const char* HashName() { return "SHA-256"; }
	const char* HashShortName() { return "SHA"; }
	const char* HashDescription() { return "SHA-256 (SHA-2) Secure Hash Algorithm (256-bit)"; }
	int HashLength() { return 64; }
	const char* HashFileName() { return "SHA"; }
	const char* HashFileExtension() { return ".sha2"; }
	BOOL MD5StyleHashFile() { return YES; }
};

#endif	// __SHA_256_H__INCLUDED_
