#pragma once

#include <iostream>
#include "../cmagic/cmagic.h"
#include "mkl.h"

/**
 *
 * @brief Dies ist die Matrixklasse die die Standardmethoden implementiert.
 * @author dln-dev 
 * @version 0.1
 * @date 30.06.2016
 *
 */

class CMatrix {
	private:
	unsigned short int i, j, k;  // for loops
	int rows, cols;
	float **matrix;

	public:

	/**
	 * dieser Konstruktor wird fuer quadr. Matrizen gebraucht
	 * @see CMatrix(float**, const unsigned short int, const unsigned short int)
	 *
	 *
	 */
	CMatrix(float **values, const unsigned short int dim) : 
		CMatrix(values, dim, dim) {}
	CMatrix(const unsigned short int rowDim, const unsigned short int colDim) :
		CMatrix(nullptr, rowDim, colDim) {}

	/**
	 * @brief Dies ist der Standardkonstruktor
	 * @param[in] values Values beinhaltet das Array mit den Matrixelementen
	 * @param[in] rowDim beinhaltet die Zeilendimension
	 * @param[in] colDim beinhaltet die Spaltendimension
	 *
	 */
	CMatrix(float **values, const unsigned short int rowDim, const unsigned short int colDim);
	CMatrix(const CMatrix &values) : 
		CMatrix(nullptr, values.getRows(), values.getCols()) {this->matSum(&values);}

	void matSum(const CMatrix *mat);
	void matMult(const CMatrix *mat);
	void transpose();
	void inverse();
	/**
	 * @brief diese Methode berechnet das Skalarprodukt
	 *
	 * @param[in] mat Erwartet wird ein dynamisches Matrixobjekt mit passender Dimension
	 *
	 * @return das Skalarprodukt der aktuellen Matrix mit der uebergebenen
	 */
	float scalarProduct(const CMatrix *mat); // 2-norm 

	unsigned short int getRows() const;
	unsigned short int getCols() const;
	float getElem(unsigned short int n, unsigned short int m) const; // start counting at 0

	void print();

	CMatrix& operator=(const CMatrix &mat);

	~CMatrix();
};
