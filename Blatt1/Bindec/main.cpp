// iostream already included in bindec.h
#include "bindec.h"

using namespace std;

int main(void)
{
	short int mode = 0;
	
	while(mode != 3) {
		cout << "choose mode: \n";
		cout << "1: decimal to binary\n";
		cout << "2: binary to decimal\n";
		cout << "3: stop and exit\n" << endl;

		cin >> mode;

		switch(mode) {
			case 1 : {decbin(); break;}
			case 2 : {bindec(); break;}
			case 3 : break;
			default  : {mode = 0; break;}
		}
	}

	return 0;
}
