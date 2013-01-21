//
// Hash.h: interface for the CHash abstract class.
//
// Created by Mark Muir 2005/1/3
// Copyright 2005 Mark Muir. All rights reserved.
//
// Abstract class for hash algorithms. Defines the functionality that a hash
// alogirthm should support (i.e. the ability to create a hash string from a
// given text message or file), and provides and implements a set of static
// member functions that provide some useful formatting of file sizes etc.
// When creating a hash of a file, a concrete sub-class should implement the
// CalculateHash() function such that it prints to stdout the size of the file,
// followed by a frequently updated progress bar (consisting of a bar of length
// PROGRESS_BAR_LENGTH, followed by a space and the integer percentage value).
// The file size text should be padded with trailing white space to make it at
// least iColumnWidth characters wide, after which the progress bar is drawn.
// Always at least one space follows the text. Upon completion, the progress
// bar is erased, leaving the insertion point at the end of the white space,
// ready for the caller to print some terminating text (e.g. the hash string).
// If iColumnWidth is 0 (default), the only white space generated is the final
// ' '. Further methods must be implemented by a sub-class: one to return a
// unique string that identifies the algorithm (a reasonably short version of
// the algorithm's name), another for returning a short string for the
// algorithm (as short as possible - for use in displaying next to hash values),
// another for returning the length of the hash string (e.g. the number of hex
// digits), and others to return the file extension and name given to hash
// files that would normally contain hash entries of the type created by the
// sub-class.

#ifndef __HASH_H__INCLUDED__
#define __HASH_H__INCLUDED__

#include <stdio.h>

#define BLOCK_SIZE				1048576		// Number of bytes to read at a time from storage
#define PROGRESS_BAR_LENGTH		20			// Number of characters that make up the progress bar

#define BOOL	int
#define YES		1
#define NO		0

class CHash
{
protected:
	unsigned char m_ucBuffer[BLOCK_SIZE];	// File read buffer
	
public:
	virtual const char* CalculateHash(const char *szText) = 0;	// Calculate the hash for the given text message
	virtual const char* CalculateHash(FILE *fin, int iColumnWidth = 0) = 0;	// Calculate the hash for the given file, maintaining a progress bar
public:
	virtual const char* HashName() = 0;		// Return the (unique) name of the hashing algorithm
	virtual const char* HashShortName() = 0;// Return the short name of the hashing algorithm, for use in displaying next to hash values
	virtual const char* HashDescription() = 0;	// Returns a string with a descriptive name of the hash algorithm (e.g. a long name)
	virtual int HashLength() = 0;	// Return the length of the hash string (typically the number of hex digits)
	virtual const char* HashFileName() = 0;	// Returns the name given to the type of hash file that would normally contain hash entries of this type
	virtual const char* HashFileExtension() = 0;	// Returns the file extension (including the dot) associated to the type of hash file that would contain these hash entries
	virtual BOOL MD5StyleHashFile() { return YES; }	// Do the hash files for this type use the MD5-style layout, or the SFV-style layout?

	static int ProgressMessageLength() { return PROGRESS_BAR_LENGTH + 5; }	// The length of the progress bar plus text
	
public:
	static void InsertCommas(double number, char *szOut, int bInteger);
	static void FileSizeToText(unsigned long ulSize, char *szOut, int bAsExactBytes);
};

#endif	// __HASH_H__INCLUDED__
