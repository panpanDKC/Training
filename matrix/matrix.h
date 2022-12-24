#include <stdlib.h>
#include <stdio.h>

typedef struct matrix{
	double* data;
	size_t rows;
	size_t cols;
}matrix;

matrix* init_mat(size_t rows, size_t cols);
matrix* copy_mat(matrix* m);
void print_mat(matrix* m);
matrix* add_mat(matrix* m1, matrix* m2);
matrix* sub_mat(matrix* m1, matrix* m2);
matrix* dot_mat(matrix* m1, matrix* m2);
matrix* pow_mat(matrix* m, int x);
matrix* dumb_mult_mat(matrix* m1, matrix* m2);
matrix* transpose_mat(matrix* m);
double sum_of_mat(matrix* m);
