#pragma once

#include "CArray.h"

class CMatrix {
	private:
	int n, m; // rows, columns
	int **matrix;

	public:
	CMatrix(int values[][dim], unsigned int dim) : 
		CMatrix(values, dim, dim) {}
	CMatrix(unsigned int rowDim, unsigned int colDim) :
		CMatrix(nullptr, rowDim, colDim) {}
	CMatrix(int values[][colDim], unsigned int rowDim, unsigned int colDim);
	CMatrix(const CMatrix &obj);

	void matSum(CMatrix *mat);
	void matMult(CMatrix *mat);
	void transpose();
	void inverse();
	long int scalarProduct(CMatrix *mat); // multiplies, then sums elements at same locations

	CMatrix operator=(const CMatrix &mat);

	~CMatrix();
};
