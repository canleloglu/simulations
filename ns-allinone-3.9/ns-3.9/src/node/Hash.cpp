//
// Hash.cpp: implementation of the CHash abstract class.
//
// Created by Mark Muir 2005/1/3
// Copyright 2005 Mark Muir. All rights reserved.
//
// Abstract class for hash algorithms. Defines the functionality that a hash
// alogirthm should support (i.e. the ability to create a hash string from a
// given text message or file), and provides and implements a set of static
// member functions that provide some useful formatting of file sizes etc.

#include <math.h>
#include <string.h>
#include "Hash.h"


//------------------------------
// Class Method Implementations
//------------------------------

// InsertCommas()
// Function to create a text string of a number seperated by commas every 10^(3n).
// Numbers are printed to two decimal places if non-integer, or to nearest integer
// if last parameter is set.
void CHash::InsertCommas(double number, char *szOut, int bInteger)
{
	int i, segments;
	
	if(number < 0)
	{
		// Place negative sign in front of negative numbers
		szOut[0] = '-';
		szOut[1] = '\0';
		number = -number;	// Make number positive for later processing
	}
	else szOut[0] = '\0';
	
	if(number < 1000)
	{
		// Number is small enough to be displayed without commas
		sprintf(szOut+strlen(szOut), bInteger? "%.0lf" : "%.2lf", number);
	}
	else
	{
		// Calculate the number of 3-digit segments
		segments = (int)ceil((floor(log10(number)) + 1)/3.0);
		
		// Shift number down so that most significant segment appears in the range 1-999
		for(i=1; i<segments; i++) number = number * 0.001;
		
		for(i=0; i<segments; i++)
		{
			// Display according to position of segment
			// fmod() is used to wrap the number to within the segment of interest (i.e confines to range 0-999)
			if(i==0) sprintf(szOut+strlen(szOut), "%.0lf,", floor(fmod(number, 1000)));
			else if(i<(segments-1)) sprintf(szOut+strlen(szOut), "%03.0lf,", floor(fmod(number, 1000)));
			else sprintf(szOut+strlen(szOut), bInteger? "%03.0lf" : "%06.2lf", fmod(number, 1000));
			number = number * 1000;	// Shift to next segment
		}
	}
}

// FileSizeToText()
// Function to create a text string representing a 32-bit file size to be displayed
// as part of a message. File sizes are written as a number of bytes punctuated by
// commas every 10^3n, or as a number to two decimal places of K, MB, or GB as
// specified by the last parameter.
void CHash::FileSizeToText(unsigned long ulSize, char *szOut, int bAsExactBytes)
{
	if(bAsExactBytes || ulSize < 100*1024)	// Print as "bytes" if less than 100KB
	{
		InsertCommas((double)ulSize, szOut, 1);
		sprintf(szOut+strlen(szOut), " %s", (ulSize==1)? "byte" : "bytes");
	}
	else
	{
		if(ulSize < 1024*1024)	// Print as "KB" if less than 1MB
		{
			InsertCommas((double)ulSize/1024.0, szOut, 0);
			strcat(szOut, " KB");
		}
		else if(ulSize < 1024*1024*1024)	// Print as "MB" if less than 1GB
		{
			InsertCommas((double)ulSize/(1024.0*1024.0), szOut, 0);
			strcat(szOut, " MB");
		}
		else	// Print as "GB" otherwise
		{
			InsertCommas((double)ulSize/(1024.0*1024.0*1024.0), szOut, 0);
			strcat(szOut, " GB");
		}
	}
}
