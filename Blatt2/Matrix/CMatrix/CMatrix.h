#pragma once

#include <iostream>
#include "../cmagic/cmagic.h"
#include "mkl.h"

class CMatrix {
	private:
	unsigned short int i, j, k;  // for loops
	int rows, cols;
	float **matrix;

	public:
	CMatrix(float **values, const unsigned short int dim) : 
		CMatrix(values, dim, dim) {}
	CMatrix(const unsigned short int rowDim, const unsigned short int colDim) :
		CMatrix(nullptr, rowDim, colDim) {}
	CMatrix(float **values, const unsigned short int rowDim, const unsigned short int colDim);
	CMatrix(const CMatrix &values) : 
		CMatrix(nullptr, values.getRows(), values.getCols()) {this->matSum(&values);}

	void matSum(const CMatrix *mat);
	void matMult(const CMatrix *mat);
	void transpose();
	void inverse();
	float scalarProduct(const CMatrix *mat); // multiplies, then sums elements at same locations

	unsigned short int getRows() const;
	unsigned short int getCols() const;
	float getElem(unsigned short int n, unsigned short int m) const; // start counting at 0

	void print();

	CMatrix& operator=(const CMatrix &mat);

	~CMatrix();
};
