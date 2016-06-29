#include "CMatrix.h"

CMatrix::CMatrix(int **values, const unsigned short int rowDim, const unsigned short int colDim) {
	rows = rowDim;
	cols = colDim;

	matrix = dynMatrix(rowDim, colDim);

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
		std::cerr << "non-matching matrix dimensions in matSum" << std::endl;
}

void CMatrix::matMult(const CMatrix *multiplicant) {
	if(cols == multiplicant->getRows() && rows == multiplicant->getCols()) {
		int **buffer = dynMatrix(rows, rows);

		for(i = 0; i < rows; i++)
			for(j = 0; j < rows; j++)
				for(k = 0; k < cols; k++)
					buffer[i][j] += matrix[i][k] * multiplicant->getElem(k,j);

		delete[] matrix[0];
		delete[] matrix;

		matrix = buffer;
	}
	else
		std::cerr << "non-matching dimensions in matMult" << std::endl;

}

void CMatrix::transpose() {
	if(rows == cols) 
		for(i = 0; i < rows; i++)
			for(j = i+1; j < cols; j++) {
				matrix[i][j] += matrix[j][i];
				matrix[j][i]  = matrix[i][j] - matrix[j][i];
				matrix[i][j] -= matrix[j][i];
			}
	else {
		int **buffer = dynMatrix(cols, rows);

		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				buffer[i][j] = matrix[j][i];

		delete[] matrix[0];
		delete[] matrix;

		matrix = buffer;
	}
}

void CMatrix::inverse() {
	LAPACKE_sgetri(LAPACK_ROW_MAJOR, cols, LAPACKE_sgetrf(LAPACK_ROW_MAJOR, rows, cols, matrix, cols), cols, )
}

long int CMatrix::scalarProduct(const CMatrix *vecMat) {
	static long int result = 0;

	if(rows == vecMat->getRows() && cols == vecMat->getCols()) 
		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				 result += matrix[i][j] * vecMat->getElem(i,j);
	else 
		std::cerr << "non-matching dimensions in scalarProduct" << std::endl;

	return result;
}

unsigned short int CMatrix::getRows() const {
	return rows;
}

unsigned short int CMatrix::getCols() const {
	return cols;
}

int CMatrix::getElem(const unsigned short int n, const unsigned short int m) const {
	return matrix[n][m];
}

void CMatrix::print() {
	for(i = 0; i < rows; i++) {
		std::cout << "\n";
		for(j = 0; j < cols; j++)
			std::cout << matrix[i][j] << " ";
	}

	std::cout << "\n\n" << std::flush;
}

CMatrix& CMatrix::operator=(const CMatrix &mat) {
	if(&mat != this) {
		static unsigned short int matRows, matCols;

		matRows = mat.getRows();
		matCols = mat.getCols();

		int **buffer = dynMatrix(matRows, matCols);

		for(i = 0; i < matRows; i++)
			for(j = 0; j < matCols; j++)
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
