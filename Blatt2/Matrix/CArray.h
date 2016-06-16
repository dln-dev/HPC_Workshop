#pragma once

class CArray {
	private:
	int array[][];
	unsigned int rows, cols;

	public:
	CArray() : CArray(0, 0, {{0},{0}}) {}
	CArray(int values[][]) : 
