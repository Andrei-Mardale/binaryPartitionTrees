/* MARDALE Andrei-Iulian - 311CB */

#include "bsp.h"

Tree readTree (FILE *in, TLine *lines) {
	TNodeInfo inf;
	fscanf(in, "%d %hhu %hhu", &inf.i, &inf.left, &inf.right);
	
	//create new element specifying type (LINE) and values
	TElement temp = {LINE, lines[inf.i].a, lines[inf.i].b, lines[inf.i].c};
	
	//create leaf with information
	Tree T = newLeaf(&temp, sizeof(TElement));
	
	//complete it with children if needed
	if (inf.left) readTreeAux (in, &T->left, lines);
	if (inf.right) readTreeAux (in, &T->right, lines);
	
	return T;
}

void readTreeAux (FILE *in, ATree aT, TLine *lines) {
	TNodeInfo inf;
	fscanf(in, "%d %hhu %hhu", &inf.i, &inf.left, &inf.right);
	
	//same algorithm as above
	TElement temp = {LINE, lines[inf.i].a, lines[inf.i].b, lines[inf.i].c};
	
	Tree T = newLeaf(&temp, sizeof(TElement));
	*aT = T;
	
	if (inf.left) readTreeAux (in, &T->left, lines);
	if (inf.right) readTreeAux (in, &T->right, lines);
}

Tree buildTree (TLine *line, int n) {
	Tree T = NULL;
	
	for (int i = 0; i < n; i++) {
		addLine(&T, &line[i]);
	}
	
	return T;
}

void addLine (ATree aT, TLine *line) {
	//if NULL is reached then create new leaf
	if (!(*aT)) {
		TElement temp = {LINE, line->a, line->b, line->c};
		Tree aux = newLeaf(&temp, sizeof(TElement));
		*aT = aux;
		
		return;
	}
	
	//compare lines
	int test = compareLine((*aT)->info, line);
	
	//choose branch accordingly
	if (test == 0) {
		addLine(&(*aT)->left, line);
		addLine(&(*aT)->right, line);
	} else if (test < 0) {
		addLine(&(*aT)->left, line);
	} else {
		addLine(&(*aT)->right, line);
	}
}

void labelRegions (Tree T, TPoint *points, int m) {
	for (int i = 0; i < m; i++) {
		solvePoint(&T, &points[i], i);
	}
}


/* MARDALE Andrei-Iulian - 311CB */

void solvePoint (ATree aT, TPoint *p, int index) {
	//reached a NULL pointer == region
	//therefore label that region with p's index
	if (!(*aT)) {
		//aux is not a line
		//it represents the coordinates of p and the index (=label) of the subregion
		TElement temp = {POINT, p->x, p->y, index}; 
		*aT = newLeaf(&temp, sizeof(TElement));
		return;
	}
	
	//have not reached a region yet (still have to decide on lines)
	//keep advancing
	int test = decidePoint ((*aT)->info, p);
	if (test < 0) {
		solvePoint(&(*aT)->left, p, index);
	} else {
		solvePoint(&(*aT)->right, p, index);
	}
}

void printTree (FILE *out, Tree T) {
	if (!T) return;
	
	//if line encountered then check if children are null
	//if they are, then print "null" (unlabeled region)
	//else print their values
	//if point then print value
	if (IS_LINE((TElement *) T->info)) {
		if (!(T->left)) {
			fprintf(out, "null");
		} else {
			printTree(out, T->left);
		}
			
		if (!(T->right)) {
			fprintf(out, "null");
		} else {
			printTree(out, T->right);
		}
		
		fprintf(out, "(%d,%d,%d)",
			((TElement *) T->info)->a,
			((TElement *) T->info)->b,
			((TElement *) T->info)->c
		);
	}	else { //if not line; then point
		fprintf(out, "((%d,%d)-%d)",
			((TElement *) T->info)->a,
			((TElement *) T->info)->b,
			((TElement *) T->info)->c
		);
	}
}

void localizePoints (FILE *in, FILE *out, Tree T) {
	int n = 0;
	fscanf(in, "%d", &n);
	TPoint p;
	
	for (int i = 0; i < n; i++) {
		fscanf(in, "%d %d", &p.x, &p.y);
		int t = localizePoint(T, &p);
		fprintf(out, "%d\n", t);
	}
}

int localizePoint (Tree T, TPoint *p) {
	if (!T) return -1; //should not get here
	
	//leaf found, print region label
	if (T->left == NULL && T->right == NULL) {
		return ((TElement *) T->info)->c;
	}
	
	int test = decidePoint(T->info, p);
	
	//check which branch needs to be follow based on test
	if (test < 0) {
		return localizePoint(T->left, p);
	} else {
		return localizePoint(T->right, p);
	}
	
	return -1; //nor here
}
	
	
			
			
	
	
	
	
	
	
			
