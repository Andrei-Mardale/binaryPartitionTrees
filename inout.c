/* MARDALE Andrei-Iulian - 311CB */

#include "inout.h"

TLine * getLines (FILE *in, int *n) {
	//get number of lines
	fscanf(in, "%d", n);
	
	TLine *lines = malloc(*n * sizeof(TLine));
	if (!lines) return NULL;
	
	//read each line
	for (int i = 0; i < *n; i++) {
		fscanf(in, "%d %d %d", &lines[i].a, &lines[i].b, &lines[i].c);
	}
	
	return lines;
}

TPoint * getPoints (FILE *in, int *n) {
	//get number of points
	fscanf(in, "%d", n);
	
	TPoint *points = malloc(*n * sizeof(TPoint));
	if (!points) return NULL;
	
	//read each point
	for (int i = 0; i < *n; i++) {
		fscanf(in, "%d %d", &points[i].x, &points[i].y);
	}
	
	return points;
}

void readPoint (FILE *in, TPoint *p) {
	fscanf(in, "%d %d", &p->x, &p->y);
}
