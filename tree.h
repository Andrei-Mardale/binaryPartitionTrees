/* MARDALE Andrei-Iulian - 311CB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _TREE_
#define _TREE_

typedef struct Node {
	struct Node *left, *right;
	void *info;
} TNode, *Tree, **ATree;

//creates a new leaf; inf is copied into the information field
Tree newLeaf (const void *inf, size_t dim);

//destroys a Tree and sets it to NULL
void destroyTree (ATree aT);

#endif
