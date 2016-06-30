#include "CMatrix.h"

using namespace std;

CMatrix::CMatrix(float **values, const unsigned short int rowDim, const unsigned short int colDim) {
	rows = rowDim;
	cols = colDim;

	matrix = dynMatrix<float>(rowDim, colDim);

	if(values == nullptr)
		for(i = 0; i < rowDim; i++)
			for(j = 0; j < colDim; j++)
				matrix[i][j] = 0;
	else
		for(i = 0; i < rowDim; i++)
			for(j = 0; j < colDim; j++)
				matrix[i][j] = values[i][j];
}

void CMatrix::matSum(const CMatrix *summand) {
	if(summand->getRows() == rows && summand->getCols() == cols)
		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				matrix[i][j] += summand->getElem(i, j);
	else
		cerr << "non-matching matrix dimensions in matSum" << endl;
}

void CMatrix::matMult(const CMatrix *multiplicant) {
	if(cols == multiplicant->getRows()) {
		static unsigned short int multiplicantCols = multiplicant->getCols();

		float **buffer = dynMatrix<float>(rows, multiplicantCols);

		for(i = 0; i < rows; i++)
			for(j = 0; j < multiplicantCols; j++)
				for(k = 0; k < cols; k++)
					buffer[i][j] += matrix[i][k] * multiplicant->getElem(k,j);

		delete[] matrix[0];
		delete[] matrix;

		cols = multiplicantCols;
		matrix = buffer;
	}
	else
		cerr << "non-matching dimensions in matMult" << endl;

}

void CMatrix::transpose() {
	if(rows == cols) 
		for(i = 0; i < rows; i++)
			for(j = i + 1; j < cols; j++) {
				matrix[i][j] += matrix[j][i];
				matrix[j][i]  = matrix[i][j] - matrix[j][i];
				matrix[i][j] -= matrix[j][i];
			}
	else {
		float **buffer = dynMatrix<float>(cols, rows);

		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				buffer[i][j] = matrix[j][i];

		delete[] matrix[0];
		delete[] matrix;

		rows += cols;
		cols  = rows - cols;
		rows -= cols;

		matrix = buffer;
	}
}

void CMatrix::inverse() {
	if(rows == cols) {
		int *a = new int[rows*cols];

		// careful! These only act on float matrices.
		if(LAPACKE_sgetrf(LAPACK_COL_MAJOR, rows, cols, matrix[0], cols, a) != 0)
			cerr << "LU decomposition failed" << endl;

		if(LAPACKE_sgetri(LAPACK_COL_MAJOR, cols, matrix[0], cols, a) != 0)
			cerr << "inversion failed, matrix singular?" << endl;

		delete[] a;
	}
	else
		cout << "inverse only for square matrices" << endl;
}

float CMatrix::scalarProduct(const CMatrix *vecMat) {
	static float result = 0;

	if(rows == vecMat->getRows() && cols == vecMat->getCols()) 
		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				 result += matrix[i][j] * vecMat->getElem(i,j);
	else 
		cerr << "non-matching dimensions in scalarProduct" << endl;

	return result;
}

unsigned short int CMatrix::getRows() const {
	return rows;
}

unsigned short int CMatrix::getCols() const {
	return cols;
}

float CMatrix::getElem(const unsigned short int m, const unsigned short int n) const {
	// todo: test for oob
	return matrix[m][n];
}

void CMatrix::print() {
	for(i = 0; i < rows; i++) {
		cout << "\n";
		for(j = 0; j < cols; j++)
			cout << matrix[i][j] << " ";
	}

	cout << "\n\n" << flush;
}

CMatrix& CMatrix::operator=(const CMatrix &mat) {
	if(&mat != this) {
		rows = mat.getRows();
		cols = mat.getCols();

		float **buffer = dynMatrix<float>(rows, cols);

		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				buffer[i][j] = mat.getElem(i, j);

		delete[] matrix[0];
		delete[] matrix;

		matrix = buffer;
	}

	return *this;
}


CMatrix::~CMatrix() {
	delete[] matrix[0];
	delete[] matrix;
}
