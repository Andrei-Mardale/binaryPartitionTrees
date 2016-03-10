/* MARDALE Andrei-Iulian - 311CB */

#include "tree.h"
#include "inout.h"

#ifndef _BSP_
#define _BSP_

//a structure that keeps some basic info about a node
//needed for reading BSP form file

//inits the reading - creates main node
Tree readTree (FILE *in, TLine *lines);

//reads nodes in pre-order
void readTreeAux (FILE *in, ATree aT, TLine *lines);

//builds a tree using the line vector
Tree buildTree (TLine *line, int n);

//adds line to tree
void addLine (ATree aT, TLine *line);

//label regions using given points (by their indexes)
//m is the number of points
void labelRegions (Tree T, TPoint *points, int m);

//subroutine of function labelRegions
//labels a single region coresponding to point p with index "index"
//assumes T is not NULL
void solvePoint (ATree aT, TPoint *p, int index);

//prints Tree (post-order)
void printTree (FILE *out, Tree T);

//prints the regions for all the points in p
void localizePoints (FILE *in, FILE *out, Tree T);

//returns the label of the region that the points belongs to
int localizePoint (Tree T, TPoint *p);

//function that acts accordingly to operationg mode 1
void mode1 (FILE *in, FILE *out);

//function that acts accordingly to operationg mode 2
void mode2 (FILE *in, FILE *out);
#endif
