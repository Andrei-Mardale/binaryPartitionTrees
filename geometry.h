/* MARDALE Andrei-Iulian - 311CB */

#ifndef _GEOMETRY_
#define _GEOMETRY_

#define LINE 0
#define POINT 1

#define IS_LINE(El) (!((El)->type))
#define IS_POINT(El) ((El)->type)

typedef struct {
	int a, b, c;
} TLine;

typedef struct {
	int x, y;
} TPoint;

//abstract element type
//can be both point (with region label) or line
//access mode determined by what is found in type
typedef struct {
	char type; // 0 / 1
	int a, b, c;
} TElement;

//returns 0 if they are NOT parallel, -1 if only left tree needs to be worked on, 1 if right
//line will be given as TElement (function will be called for elements in tree)
int compareLine (TElement *el, TLine *l2);

//<0 if point is on left; >0 on right, 0 on line
//line will be given as TElement (function will be called for elements in tree)
int decidePoint (TElement *el, TPoint *p); 

#endif
