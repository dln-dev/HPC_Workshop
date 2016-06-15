#include <iostream>

using namespace std;

int main(void)
{
	int feld[15] = {7, 3, 1, 27, 8, 6, 12, 4, 9, 14, 25, 19, 13, 5, 99};
	short int last = sizeof(feld)/sizeof(*feld) - 1;	
	
	for(short int i = 0; i < last/2; i++) {
		feld[i] += feld[last - i];
		feld[last - i] = feld[i] - feld[last - i];
		feld[i] -= feld[last - i];
	}

	cout << "Die Zahlen des Arrays in umgekehrter Reihenfolge: ";
	for(short int i = 0; i < 15; i++)
		cout << feld[i] << " ";
	cout << endl;

	return 0;
}
