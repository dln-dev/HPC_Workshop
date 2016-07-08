#include <iostream>
#include "../CMatrix/CMatrix.h"
#include <chrono>
//#include <typeinfo>

using namespace std;
using namespace std::chrono;

int main(void) {
	float  A_stat[][2] = {{1,2},{3,0}};
	float *A_init[2] = {A_stat[0], A_stat[1]};
	float  B_stat[][3] = {{4,6,8},{11,2,12},{3,5,16}};
	float *B_init[3] = {B_stat[0], B_stat[1], B_stat[2]};
	float  H_stat[][3] = {{2,4,-2},{4,9,-3},{-2,-3,7}};
	float *H_init[3] = {H_stat[0], H_stat[1], H_stat[2]};

	float  b_stat[][1] = {{1},{3}};
	float *b_init[2] = {b_stat[0], b_stat[1]};
	float  u_stat[][3] = {4,6,8};
	float *u_init[1] = {u_stat[0]};
	float  v_stat[][1] = {{2},{8},{10}};
	float *v_init[3] = {v_stat[0], v_stat[1], v_stat[2]};

	CMatrix A = CMatrix(A_init, 2, 2);
	CMatrix B = CMatrix(B_init, 3, 3);
	CMatrix H = CMatrix(H_init, 3, 3);
	CMatrix C = A;
	CMatrix R = CMatrix(50000, 1000, 1, 100);
	CMatrix S = CMatrix(1000, 50000, 1, 100);

	CMatrix b = CMatrix(b_init, 2, 1);
	CMatrix u = CMatrix(u_init, 1, 3);
	CMatrix v = CMatrix(v_init, 3, 1);

	cout << "Start matMult" << endl;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	S.matMult(&R);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(t2 - t1).count();

	cout << "computing time ~ " << duration << "s " << endl;

	/*A.print();
	B.print();
	H.print();

	b.print();
	u.print();
	v.print();

	C.inverse();
	C.matMult(&A);

	C.print();
	C.addRandom(1,100);
	C.print();*/
	
	/*for(unsigned short int i = 0; i < 10; i++)
		cout << R.getElem(i,i) << " ";

	cout << endl;*/

	return 0;
}
