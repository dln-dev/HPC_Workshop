#include "bindec.h"

using namespace std;

static void binary(unsigned int input) {
	unsigned int remainder;
	remainder = 0; // Y U NO WORK WITH STATIC

	if(input <= 1) {
		cout << input;
		return;
	}

	remainder = input%2;
	binary(input >> 1);
	cout << remainder;
}

static void decimal(unsigned long int input) {
	static unsigned int increment;
	static unsigned int result;
	increment = 1;
	result = 0;

	while(input != 0)
	{
		if(input % 10 == 1) {
			result += increment;
			input--;
		}
		input /= 10;
		increment *= 2;
	}
	cout << result;
}

void bindec() {
	static unsigned long int input;
	input = 0;

	while(input < 1) {
		cout << "unsigned binary number to convert: \n";
		cin >> input;
	}
	cout << "\nbinary:\t\tdecimal:\n";
	cout << input << "\t\t";
	decimal(input);
	cout << "\n\n" << endl;
}

void decbin() {
	static unsigned int input;
	input = 0;
	
	while(input < 1) {
		cout << "positive decimal number to convert: \n";
		cin >> input;
	}
	cout << "\ndecimal:\t\tbinary:\n";
	cout << input << "\t\t";
	binary(input);
	cout << "\n\n" << endl;
}

