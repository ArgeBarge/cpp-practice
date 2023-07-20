
#include <cstdlib>
#include "matrix.h"
#include <iostream>
#include <cmath>


Matrix::Matrix(int m, int n) {

	this->m = m;
	this->n = n;

	this->data = new int[this->m * this->n];

	if (this->data != NULL)
	{
		for (int i = 0; i < (this->m * this->n); i++)
			this->data[i] = 0;
	}
}

int &Matrix::get_val(int y, int x)
{
	return (this->data[(y * this->n) + x]);
}

int Matrix::set(std::string s)
{
	/*int i = 0;
	char* cs = (char *) s.c_str();
	const char d[2] = ",";

	char *token = strtok(cs, d);
	
	while (token != NULL)
	{
		token = strtok(NULL, cs);
		this->data[i++] = atoi(token);
	}*/
	std::string delimiter = ",";
	size_t pos = 0;

	std::string token;

	int i = 0;
	std::cout << sizeof(this->data) << " Size of array";
	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		if (i > sizeof(this->data))
			return 1;

		token = s.substr(0, pos);
		//std::cout << token << std::endl;
		this->data[i++] = std::stoi(token);
		s.erase(0, pos + delimiter.length());
	} 

	return 0;
}

void Matrix::print()
{
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			std::cout << this->data[(i * this->n) + j] << ",";
		}
		std::cout << "\n";
	}
}

int Matrix::get_rows() {
	return this->n;
}

int Matrix::get_columns() {
	return this->m;
}

void Matrix::free() {
	delete[] this->data;
}

Matrix *Matrix::operator+ (const Matrix *param)
{
	if (param == NULL)
		return NULL;
	
	if (this->get_rows() != param->n)
		return NULL;
	if (this->get_columns() != param->m)
		return NULL;

}

Matrix *multiply_matrices(const Matrix *matrix1, const Matrix *matrix2)
{	
	Matrix* mpter;

	Matrix m1 = *matrix1;
	Matrix m2 = *matrix2;

	std::cout << m1.get_rows() << std::endl;
	std::cout << m2.get_columns() << std::endl;
;	
	if(m1.get_columns() != m2.get_rows())
		return mpter=NULL;

	//Matrix result_matrix(m1.get_columns(), m2.get_rows());

	mpter = new Matrix(m1.get_columns(), m2.get_rows());

	for (int i = 0; i < m2.get_columns(); i++)
	{
		for (int j = 0; j < m2.get_rows(); j++)
		{
			for (int k = 0; k < m2.get_columns(); k++)
			{
				(mpter->get_val(i, j)) += ((m2.get_val(j, k)) * (m1.get_val(i, k)));
			}
		}
	}

	return mpter;
}

Matrix *add_matrices(const Matrix *matrix1, const Matrix *matrix2)
{	
	Matrix* mpter;

	if (matrix1 == NULL || matrix2 == NULL)
		mpter = NULL;

	Matrix m1 = *matrix1;
	Matrix m2 = *matrix2;

	if (m1.get_columns() != m2.get_columns())
		return mpter = NULL;
	if (m1.get_rows() != m2.get_rows())
		return mpter = NULL;

	mpter = new Matrix(m1.get_rows(), m2.get_columns());
	
	for (int i = 0; i < m1.get_rows(); i++)
	{
		for (int j = 0; j < m1.get_columns(); j++)
		{
			(mpter->get_val(i, j)) += (m1.get_val(i, j));
			(mpter->get_val(i, j)) += (m2.get_val(i, j));
		}
	}

	return mpter;
	
}

Matrix* init_matrix(int m, int n)
{
	return new Matrix(m, n);
}

Matrix* init_matrix(int m)
{
	return new Matrix(m, m);
}

Matrix* get_i_matrix(int a) {

	Matrix* matrix = init_matrix(a, a);

	for (int i = 0;i < matrix->get_rows();i++)
		(matrix->get_val(i, i)) += 1;

	return matrix;
}

int free_matrix(Matrix* matrix)
{
	if (matrix != NULL)
	{
		matrix->free();
		delete matrix;
		return 0;
	}
	return 1;
}

int get_determinant(Matrix* matrix)
{
	int sign;
	int det_val = 0;

	if (matrix->get_columns() * matrix->get_rows() == 1)
		return (matrix->get_val(0, 0));
	else
	{
		for (int i = 0; i < matrix->get_columns(); i++)
		{
			Matrix* sub_matrix = get_submatrix(matrix, i);
			//std::cout << "\n";
			//sub_matrix->print();
			sign = pow(-1, i);
			det_val += sign * matrix->get_val(0, i) * get_determinant(sub_matrix);
		}
	}

	return det_val;
}

Matrix* get_submatrix(Matrix* matrix, int column)
{
	if (column >= matrix->get_columns() || matrix == NULL)
		return NULL;
	
	
	Matrix* sub_matrix = init_matrix(matrix->get_rows()-1, matrix->get_columns()-1);
	
	int* ptr = &sub_matrix->get_val(0, 0);

	for (int i = 1; i < matrix->get_rows(); i++)
	{
		for (int j = 0; j < matrix->get_columns(); j++)
		{
			if (j != column)
			{
				*ptr = matrix->get_val(i, j);
				ptr++;
			}
		}
	}

	return sub_matrix;
}

int is_invertible(Matrix* matrix)
{
	if (get_determinant(matrix) == 0)
		return 0;
	else
		return 1;
}