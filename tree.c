/* MARDALE Andrei-Iulian - 311CB */

#include "tree.h"

Tree newLeaf (const void *inf, size_t dim) {
	Tree T = malloc(sizeof(TNode));
	if (!T) return NULL;
	
	T->info = malloc(dim);
	
	if(!(T->info)) {
		free(T);
		return NULL;
	}
	
	memcpy(T->info, inf, dim);
	
	//init
	T->left = NULL;
	T->right = NULL;
	
	return T;
}

void destroyTree (ATree aT) {
	if (!(*aT)) return;
	
	destroyTree(&(*aT)->left);
	destroyTree(&(*aT)->right);
	
	free((*aT)->info);
	free(*aT);
	*aT = NULL;
}
	
	
