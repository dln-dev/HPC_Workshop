#include <iostream>

using namespace std;

int main(void) {
	int ** matrix;
	unsigned int i,j;

	matrix = new int*[10];
	matrix[0] = new int[100];

	for(i = 1; i < 10; i++)
		matrix[i] = matrix[i-1] + 10;

	cout << sizeof(matrix) << endl;

	delete matrix[0];
	delete matrix;
	
	return 0;
}
