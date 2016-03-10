/* MARDALE Andrei-Iulian - 311CB */

#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"
#include "math.h"

#ifndef _INOUT_
#define _INOUT_

typedef struct {
	int i; //index 
	unsigned char left, right;
} TNodeInfo;

//gets all lines from file and returns them in a vector
TLine * getLines (FILE *in, int *n);

//gets all points from file and returns them in a vector
TPoint * getPoints (FILE *in, int *n);
#endif
