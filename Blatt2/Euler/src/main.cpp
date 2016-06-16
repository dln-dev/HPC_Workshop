#include <iostream>
#include <sstream>
#include <cmath>
#include "../cmagic/cmagic.h"

using namespace std;

int main(int argc, char* argv[]) {
if(argc == 2) {
	double x;
	stringstream(argv[1]) >> x;

	unsigned short int i;
	unsigned short int n = 5;
	unsigned short int j = 1;

	float quickE = 0;
	double loopE = 1;
	double mathE = exp(x);
	float tolerance = 1.0E-6;

	cout << x << endl;

	cout.precision(12);

	for(i = 0; i < n; i++) 
		quickE += x / factorial(i);

	while(abs((loopE - mathE)/mathE) > tolerance) 
		loopE += x / staticFac(j++);

	cout << "\ncmath:\t\t" << mathE << "\n";
	cout << "---------------------------------\n";
	cout << "5 step euler:\t" << quickE << "\n";
	cout << "rel error:\t" << abs((quickE-mathE)/mathE) << "\n\n";
	cout << "tolerance euler:" << loopE << "\n";
	cout << "rel error:\t" << abs((loopE-mathE)/mathE) << "\n" << endl;
}
else {
	cout << "\nUsage: euler.out <x>\n\nx gives the argument of the euler function\n" << endl;
}
 
	return 0;
}

