# binaryPartitionTrees
My third Data Structures homework

A C implementation of binary partition trees. Given a 2-dimensional space and N lines which produce binary splits, the program builds a binary partitioning tree allowing for linear queries about the hyperplane (in this instance, simply a plane) in which an object (which in this instance is a point) resides.

#How to compile
Run "make build"

#How to run
Syntax: "./tema3 mode data.in data.out", where:
* mode - operation mode (1 or 2) - will be explained in the next section
* data.in - input file
* data.out - output file

#Input data format
The functionality is the same, but the input data differs with respect to operation mode.

In mode 1, the syntax is as follows:
* N - number of lines
* a_i b_i c_i - line parameters
* M - number of points
* x_i y_i - point coordinates
* node_i hasLeftChild hasRightChild - tree configuration
* Q - number of queries
* x_i y_i - coordinates of queried point

In mode 2, the syntax is:
* N - number of lines
* a_i b_i c_i - line parameters
* M - number of points
* x_i y_i - point coordinates
* Q - number of queries
* x_i y_i - coordinates of queried point