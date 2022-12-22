#include <stdlib.h>
#include <stdio.h>

typedef struct matrix{
	double* data;
	size_t rows;
	size_t cols;
}matrix;

matrix* init_mat(size_t rows, size_t cols);
void print_mat(matrix* m);
matrix* add_mat(matrix* m1, matrix* m2);
matrix* dot_mat(matrix* m1, matrix* m2);
