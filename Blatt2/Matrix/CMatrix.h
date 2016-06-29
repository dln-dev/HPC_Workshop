#pragma once

#include <iostream>

class CMatrix {
	private:
	int rows, cols;
	int **matrix;

	public:
	CMatrix(int **values, const unsigned short int dim) : 
		CMatrix(values, dim, dim) {}
	CMatrix(const unsigned short int rowDim, const unsigned short int colDim) :
		CMatrix(nullptr, rowDim, colDim) {}
	CMatrix(int **values, const unsigned short int rowDim, const unsigned short int colDim);
	CMatrix(const CMatrix &values) : 
		CMatrix(nullptr, values.getRows(), values.getCols()) {this->matSum(&values);}

	void matSum(const CMatrix *mat);
	void matMult(const CMatrix *mat);
	void transpose();
	void inverse();
	long int scalarProduct(CMatrix *mat); // multiplies, then sums elements at same locations

	unsigned short int getRows() const;
	unsigned short int getCols() const;
	int getElem(unsigned short int n, unsigned short int m) const; // start counting at 0

	void print();

	CMatrix& operator=(const CMatrix &mat);

	~CMatrix();
};
