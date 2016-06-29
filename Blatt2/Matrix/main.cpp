#include <iostream>
#include "CMatrix.h"
#include <typeinfo>

using namespace std;

int main(void) {
	unsigned short int i, j;
	int ** mat = new int*[3];
	mat[0] = new int[3 * 3];
	for(i = 1; i < 3; i++)
		mat[i] = mat[i-1] + 3;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			mat[i][j] = (i+1)*j;

	int b[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int *b_dyn[3] = {b[0], b[1], b[2]};

	/*cout << c[1][1] << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(mat).name() << endl;*/
	
	CMatrix *matrix = new CMatrix(mat, 3, 3);
	CMatrix *mbtrix = new CMatrix(b_dyn, 3, 3);
	CMatrix *mctrix = new CMatrix(*matrix);
	CMatrix *mdtrix = new CMatrix(nullptr, 3,3);

	matrix->print();
	matrix->transpose();
	matrix->print();
	mbtrix->print();
	mctrix->print();
	mdtrix->print();

	matrix->matSum(mbtrix);
	matrix->print();
	mbtrix->matMult(matrix);
	mbtrix->print();
	cout << mctrix->scalarProduct(matrix) << "\n";
	mctrix->print();
	//cout << mbtrix->getElem(2,2) <<  endl;

	mctrix = matrix;
	cout << "test00";
	mctrix->print();

	delete matrix;
	delete mbtrix;
	delete mctrix;
	delete mdtrix;
	delete[] mat[0];
	delete mat;

	return 0;
}
