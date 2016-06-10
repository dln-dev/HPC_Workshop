#include <iostream>

using namespace std;

int main(void)
{
	double a[10] = {12.3, 45.78, 44.34, 23.23, 24.44, 99.4, 79.13, 71.1, 17.0, 11.19};
	double sum, harm;
	unsigned short int a_size = sizeof(a)/sizeof(*a);

	for(int i = 0; i < a_size; i++) {
		sum += a[i] / (i+1);
		harm += 1/a[i];
	}

	harm = a_size/harm;

	cout << "Gewichtete Summe:\t" << sum << endl;
	cout << "Harmonisches Mittel:\t" << harm << endl;	

	return 0;
}
