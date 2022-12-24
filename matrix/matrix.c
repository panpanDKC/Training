#include <stdio.h>
#include <err.h>
#include "matrix.h"

matrix* init_mat(size_t rows, size_t cols){
	matrix* res = malloc(sizeof(matrix));
	res->rows = rows;
	res->cols = cols;
	res->data = malloc(cols * rows * sizeof(double));
	return res;
}

matrix* copy_mat(matrix* m){
	matrix* res = init_mat(m->rows, m->cols);

	for(size_t i = 0; i < m->rows; i++){
		for(size_t j = 0; j < m->cols; j++){
			res->data[i * m->cols +j] = m->data[i * m->cols + j];
		}
	}
	return res;
}

void print_mat(matrix* m){
	for(size_t i = 0; i < m->rows; i++){
		printf("||");
		for(size_t j = 0; j < m->cols; j++){
			printf(" %.2f ||",m->data[i * m->cols + j]);
		}
		printf("\n");
	}
}

matrix* add_mat(matrix* m1, matrix* m2){
	if(m1->cols != m2->cols || m1->rows != m2->rows){
		err(1, "Addition : dimensions do not fit !\n");
	}
	
	matrix* res = init_mat(m1->rows, m1->cols);

	for(size_t i = 0; i < m1->rows; i++){
		for(size_t j = 0; j < m1->cols; j++){
			res->data[i * m1->cols + j] = m1->data[i * m1->cols + j] + m2->data[i * m1->cols + j];
		}
	}
	return res;
}

matrix* sub_mat(matrix* m1, matrix* m2){
	if(m1->cols != m2->cols || m1->rows != m2->rows){
		err(1, "Addition : dimensions do not fit !\n");
	}
	
	matrix* res = init_mat(m1->rows, m1->cols);

	for(size_t i = 0; i < m1->rows; i++){
		for(size_t j = 0; j < m1->cols; j++){
			res->data[i * m1->cols + j] = m1->data[i * m1->cols + j] - m2->data[i * m1->cols + j];
		}
	}
	return res;
}

matrix* dumb_mult_mat(matrix* m1, matrix* m2){
	if(m1->cols != m2->cols || m1->rows != m2->rows){
		err(1, "Addition : dimensions do not fit !\n");
	}

	matrix* res = init_mat(m1->rows, m2->cols);

	for(size_t i = 0; i < m1->rows; i++){
		for(size_t j = 0; j < m1->cols; j++){
			res->data[i * m1->cols + j] = m1->data[i * m1->cols +j]
				* m2->data[i * m1->cols + j];
		}
	}
	return res;
}

matrix* dot_mat(matrix* m1, matrix* m2){
	if(m1->cols != m2->rows){
		err(1,"Multiplication : dimensions do not fit !\n");
	}

	matrix* res = init_mat(m1->rows,m2->cols);
	for(size_t i = 0; i < res->rows; i++){
		for(size_t j = 0; j < res->cols; j++){
			for(size_t k = 0; k < m1->cols; k++){
				res->data[i*res->cols+j] += m1->data[i*m1->cols+k] * m2->data[k*m2->cols+j];
			}
		}
	}
	return res;
}

matrix* pow_mat(matrix* m, int x){
	matrix* res = copy_mat(m);
	while(x > 1){
		res = dumb_mult_mat(res,res);
		x--;
	}
	return res;
}

matrix* transpose_mat(matrix* m){
	matrix* res = init_mat(m->cols, m->rows);

	for(size_t i = 0; i < res->rows; i++){
		for(size_t j = 0; j < res->cols; j++){
			res->data[i * res->cols + j] = m->data[j*m->cols + i];
		}
	}
	return res;
}

double sum_of_mat(matrix* m){
	double res = 0;
	for(size_t i = 0; i < m->rows; i++){
		for(size_t j = 0; j < m->cols; j++){
			res += m->data[i * m->cols + j];
		}
	}
	return res;
}

int main(){
	matrix* m1 = init_mat(2,3);
	for(size_t i = 0; i < 6; i++){
		m1->data[i] = i;
	}
	printf("m1 : \n");
	print_mat(m1);
	
	matrix* m2 = init_mat(3,2);
	for(size_t i = 0; i < 6; i++){
		m2->data[i] = 5 - i;
	}
	printf("m2 : \n");
	print_mat(m2);

	printf("m3 : \n");
	matrix* m3 = dot_mat(m1,m2);
	print_mat(m3);

	printf("transpose m1 :\n");
	matrix* t_m1 = transpose_mat(m1);
	print_mat(t_m1);


	printf("sum of m2 :\n");
	double sum_m2 = sum_of_mat(m2);
	printf("%.2f\n",sum_m2);

	printf("pow m2 of 3 :\n");
	matrix* pow_m2 = pow_mat(m2,2);
	print_mat(pow_m2);
	return 1;
}
