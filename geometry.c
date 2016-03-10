/* MARDALE Andrei-Iulian - 311CB */

#include "geometry.h"

int compareLine (TElement *el, TLine *l2) {
	float m1 = ((float) el->a) / el->b;
	float m2 = ((float) l2->a) / l2->b;
	
	if (m1 == m2) return el->c - l2->c;
	
	return 0;
}

int decidePoint (TElement *el, TPoint *p) {
	return el->a * p->x + el->b * p->y + el->c;
}
