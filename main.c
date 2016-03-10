/* MARDALE Andrei-Iulian - 311CB */

#include "bsp.h"

int main (int argc, char *argv[]) {
	if (argc != 4) return 3;
	
	FILE *in = fopen (argv[2], "r");
	if (!in) return 2;
	
	FILE *out = fopen(argv[3], "w");
	if (!out) {
		fclose(in);
		return 2;
	}
	
	if (!strcmp(argv[1], "1")) {
		mode1(in, out);
	} else if (!strcmp(argv[1], "2")) {
		mode2(in, out);
	}
	
	fclose(in);
	fclose(out);
	
	return 0;
}

