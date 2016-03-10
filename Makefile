CC = gcc -c
LD = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g
INCLUDES = -lm

build: tema3

tema3: tree.o geometry.o inout.o bsp.o op_modes.o main.o
	$(LD) $(CFLAGS) $^ $(INCLUDES) -o $@
	
tree.o: tree.c tree.h
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@
	
geometry.o: geometry.c geometry.h
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

inout.o: inout.c inout.h geometry.h
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

bsp.o: bsp.c bsp.h tree.h inout.h geometry.h
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@
	
op_modes.o: op_modes.c bsp.h tree.h inout.h geometry.h
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

main.o: main.c geometry.h bsp.h tree.h inout.h
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

clean:
	rm -f tema3
	rm -f *.o
	rm -f *~
