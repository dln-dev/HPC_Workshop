#include "CustomDate.h" 

using namespace std;

int main(void) {
	unsigned int t, m, j;

	cout << "Geben Sie Tag, Monat und Jahr ein" << endl;
	cin >> t;
	cin >> m;
	cin >> j;

	CustomDate date = CustomDate(t, m, j);
	date.advanceDays(1);

	cout << "Nächster Tag ist ";
	date.printDate();

	return 0;
}
