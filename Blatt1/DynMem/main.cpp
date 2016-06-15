#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	unsigned short int n, k;
	unsigned short int indent;
	const unsigned short int size = atoi(argv[1]);
	unsigned int **triangle;

	// pointer setup	
	triangle = new unsigned int*[size];
	triangle[0] = new unsigned int[(size*(size+1))/2];

	// set row pointers	
	for(n = 1; n < size; n++)
		triangle[n] = triangle[n-1] + n;

	// initialize left and right sides
	for(n = 0; n < size; n++) {
		triangle[n][0] = 1;
		triangle[n][n] = 1;
	}

	// calculate inner values
	for(n = 2; n < size; n++) 
		for(k = 1; k < n; k++)
			triangle[n][k] = triangle[n-1][k-1] + triangle[n-1][k];

	// print triangle up to row SIZE
	for(n = 0; n < size; n++) {
		for(indent = 0; indent < size - n; indent++)
			cout << "  ";
		for(k = 0; k < n + 1; k++) {
			if(triangle[n][k] < 100)
				cout << " ";
			cout << triangle[n][k] << " ";
			if(triangle[n][k] < 10)
				cout << " ";
		}
		cout << endl;
	}

	// cleanup	
	delete[] triangle[0];
	delete[] triangle;

	return 0;
}
