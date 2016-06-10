#include <iostream>

using namespace std;

int main(void)
{
	unsigned int const n = 70;
	
	unsigned long int a = 1;
	unsigned long int b = 0;
	unsigned long int result = 1;

	for(int i = 1; i < n; i++) {
		b = a;
		a = result;
		result = a + b;
	}

	cout << result << endl;

	return 0;
}
