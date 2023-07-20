#pragma once
#include <string>

#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix {
	
	int m;
	int n;
	int* data;


public:

	Matrix(int m, int n);
	
	//~Matrix();
	int &get_val(int y, int x);
	int set(std::string);
	int get_rows();
	int get_columns();
	void print();
	void free();
	Matrix* operator * (const Matrix*);
	Matrix* operator + (const Matrix*);
};

Matrix* multiply_matrices(const Matrix *, const Matrix *);
Matrix* add_matrices(const Matrix*, const Matrix *);
Matrix* init_matrix(int, int);
Matrix* init_matrix(int);
Matrix* get_i_matrix(int);
int free_matrix(Matrix* );
int get_determinant(Matrix*);
Matrix* get_submatrix(Matrix*, int);
int is_invertible(Matrix*);

#endif