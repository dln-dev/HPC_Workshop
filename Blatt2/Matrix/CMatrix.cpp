#include "CMatrix.h"

CMatrix::CMatrix(const unsigned int rowDim, const unsigned int colDim, const int values[][]) {
	unsigned short int i, j;
	matrix = new int*[rowDim];

	matrix[0] = new int[rowDim * colDim];

	for(i = 1; i < rowDim; i++)
		matrix[i] = matrix[i-1] + colDim;

	if(sizeof(values) == colDim * rowDim * sizeof(int))
		for(i = 0; i < rowDim; i++)
			for(j = 0; j < colDim; j++)
				matrix[i][j] = values[i][j];
	else if(values == nullptr)
		for(i = 0; i < rowDim; i++)
			for(j = 0; j < colDim; j++)
				matrix[i][j] = 0;
	else
		exit(1);
}

CMatrix::~CMatrix() {
	delete matrix[0];
	delete matrix;
}
