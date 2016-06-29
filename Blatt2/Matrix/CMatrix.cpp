#include "CMatrix.h"

CMatrix::CMatrix(int **values, const unsigned short int rowDim, const unsigned short int colDim) {
	unsigned short int i, j;
	rows = rowDim;
	cols = colDim;

	matrix = new int*[rowDim];
	matrix[0] = new int[rowDim * colDim];
	for(i = 1; i < rowDim; i++)
		matrix[i] = matrix[i-1] + colDim;

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
	static unsigned short int i, j;
	
	if(summand->getRows() == rows && summand->getCols() == cols)
		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				matrix[i][j] += summand->getElem(i, j);
	else
		std::cerr << "non-matching matrix dimensions in matSum" << std::endl;
}

void CMatrix::matMult(const CMatrix *multiplicant) {
	static unsigned short int i, j, k;

	if(cols == multiplicant->getRows() && rows == multiplicant->getCols()) {
		int **buffer = new int*[rows];
		buffer[0] = new int[rows * rows];
		for(i = 1; i < rows; i++)
			buffer[i] = buffer[i-1] + rows;

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
	static unsigned short int i, j;

	if(rows == cols) 
		for(i = 0; i < rows; i++)
			for(j = i+1; j < cols; j++) {
				matrix[i][j] += matrix[j][i];
				matrix[j][i]  = matrix[i][j] - matrix[j][i];
				matrix[i][j] -= matrix[j][i];
				std::cout << matrix[i][j] << "  ";
			}
	else {
		int **buffer = new int*[cols];
		buffer[0] = new int[cols * rows];
		for(i = 1; i < cols; i++)
			buffer[i] = buffer[i-1] + rows;

		for(i = 0; i < rows; i++)
			for(j = 0; j < cols; j++)
				buffer[i][j] = matrix[j][i];

		delete[] matrix[0];
		delete[] matrix;

		matrix = buffer;
	}
}

long int CMatrix::scalarProduct(CMatrix *vecMat) {
	static unsigned short int i, j;
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
	unsigned short int i, j;

	for(i = 0; i < rows; i++) {
		std::cout << "\n";
		for(j = 0; j < cols; j++)
			std::cout << matrix[i][j] << " ";
	}

	std::cout << "\n\n" << std::flush;
}

CMatrix& CMatrix::operator=(const CMatrix &mat) {
	if(&mat != this) {
		static unsigned short int i, j;
		static unsigned short int matRows, matCols;
		std::cout << "test0";
		matRows = mat.getRows();
		matCols = mat.getCols();
		std::cout << "test1";

		int **buffer = new int*[matRows];
		buffer[0] = new int[matRows * matCols];
		for(i = 1; i < matRows; i++)
			buffer[i] = buffer[i-1] + matCols;

		std::cout << "test2";
		for(i = 0; i < matRows; i++)
			for(j = 0; j < matCols; j++)
				buffer[i][j] = mat.getElem(i, j);

		delete[] matrix[0];
		delete[] matrix;

		matrix = buffer;
		//CMatrix buffer = new CMatrix(*mat);
	}
	std::cout << "test5";
	return *this;
}


CMatrix::~CMatrix() {
	delete[] matrix[0];
	delete[] matrix;
}
