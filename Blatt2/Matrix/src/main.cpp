#include <iostream>
#include "../CMatrix/CMatrix.h"
#include <typeinfo>

using namespace std;

int main(void) {
	unsigned short int i, j;
	
	float ** mat = dynMatrix(3, 3);
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			mat[i][j] = (i+1)*j;

	float b[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	float *b_dyn[3] = {b[0], b[1], b[2]};

	/*cout << c[1][1] << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(mat).name() << endl;*/
	
	CMatrix matrix = CMatrix(mat, 3, 3);
	CMatrix *mbtrix = new CMatrix(b_dyn, 3, 3);
	CMatrix mctrix = CMatrix(matrix);
	CMatrix mdtrix = CMatrix(nullptr, 3,3);

	matrix.print();
	matrix.transpose();
	matrix.print();
	mbtrix->print();
	mctrix.print();
	mdtrix.print();

	matrix.matSum(mbtrix);
	matrix.print();
	mbtrix->matMult(&matrix);
	mbtrix->print();
	cout << mctrix.scalarProduct(&matrix) << "\n";
	mctrix.print();
	//cout << mbtrix->getElem(2,2) <<  endl;

	mctrix = matrix;
	cout << "test00";
	mctrix.print();

	matrix.inverse();

	matrix.print();

	delete mbtrix;
	delete[] mat[0];
	delete mat;

	return 0;
}
