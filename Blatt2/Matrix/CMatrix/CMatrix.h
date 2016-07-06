#pragma once

#include <iostream>
#include "../cmagic/cmagic.h"
#include "mkl.h"
#include <unistd.h>

class CMatrix {
	private:
	unsigned short int i, j, k;  // for loops
	int rows, cols;
	float **matrix;
	static const long int cache_linesize;

	public:

	CMatrix(float **values, const unsigned short int dim) : 
		CMatrix(values, dim, dim) {}
	CMatrix(const unsigned short int rowDim, const unsigned short int colDim) :
		CMatrix(nullptr, rowDim, colDim) {}
	CMatrix(const unsigned short int rowDim, const unsigned short int colDim, const int min, const int max) :
		CMatrix(nullptr, rowDim, colDim) {this->addRandom(min,max);}
	CMatrix(const CMatrix &values) : 
		CMatrix(nullptr, values.getRows(), values.getCols()) {this->matSum(&values);}

	CMatrix(float **values, const unsigned short int rowDim, const unsigned short int colDim);

	void matSum(const CMatrix *mat);
	void matMult(const CMatrix *mat);
	void transpose();
	void inverse();
	void addRandom(const int min, const int max);
	
	float scalarProduct(const CMatrix *mat); // 2-norm 

	unsigned short int getRows() const;
	unsigned short int getCols() const;
	float getElem(unsigned short int n, unsigned short int m) const; // start counting at 0

	void print();

	CMatrix& operator=(const CMatrix &mat);

	~CMatrix();
};
