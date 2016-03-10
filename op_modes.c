/* MARDALE Andrei-Iulian - 311CB */

#include "bsp.h"

void mode1 (FILE *in, FILE *out) {
	//line number and point number
	int ln = 0, pn = 0;
	
	//get lines 
	TLine *lines = getLines(in, &ln);
	
	//get points
	TPoint *points = getPoints(in, &pn);
	
	//read tree from file
	Tree T = readTree(in, lines);
	
	//need lines no longer
	free(lines);
	lines = NULL;
	
	//label regions using points
	labelRegions(T, points, pn);
	
	//need points no longer
	free(points);
	points = NULL;
	
	//print tree
	printTree(out, T);
	fprintf(out, "\n");
	
	//solve all points 
	localizePoints(in, out, T);
	
	destroyTree(&T);
}

void mode2 (FILE *in, FILE *out) {
	int ln = 0, pn = 0;
	
	TLine *lines = getLines(in, &ln);		
	
	//build tree using lines
	Tree T = buildTree(lines, ln);
	
	free(lines);
	lines = NULL;
	
	//reads points after building tree (better memory usage)
	TPoint *points = getPoints(in, &pn);
	
	labelRegions(T, points, pn);
	
	free(points);
	points = NULL;
	
	printTree(out, T);
	fprintf(out, "\n");
	
	localizePoints(in, out, T);
	
	destroyTree(&T);
}


	


