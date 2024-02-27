#include <iostream>
#include "Matrix.h"

int main() 
{
	//конструктор и деструктор
	Matrix matr1(4, 4);
	std::cout << "Default first matrix" << std::endl;

	//заполнение рандомными значениями
	matr1.RandFill();
	std::cout << "First matrix after being filled with random values: " << std::endl;
	std::cout << matr1 << std::endl;

	//оператор доступа
	std::cout << "Element at (2, 3):" << matr1[2][3] << std::endl;

	//оператор +=
	Matrix matr2(4, 4);
	matr2.RandFill();
	std::cout << "Default second matrix" << std::endl;
	std::cout << matr2;
	matr1 += matr2;
	std::cout << "First matrix after addition with second matrix: ";
	std::cout << matr1;

	//оператор +
	Matrix sum = matr1 + matr2;
	std::cout << "Sum of two default matrix: " << std::endl;
	std::cout << sum;

	//оператор -=
	matr1 -= matr2;
	std::cout << "First matrix after substraction with second matrix:" << std::endl;
	std::cout << matr1;

	//оператор -
	Matrix dif = matr1 - matr2;
	std::cout << "Difference of first matrix and second matrix:" << std::endl;
	std::cout << dif;

	//оператор *
	Matrix prod = matr1 * matr2;
	std::cout << "Product of first and second matrix: " << std::endl;
	std::cout << prod;
	
	//оператор *
	matr1 *= matr2;
	std::cout << "First matrix after multiplying it with second matrix: " << std::endl;
	std::cout << matr1;

	//операторы != и ==
	if (matr1 == matr2) {
		std::cout << "First matrix is equal to second matrix" << std::endl;
	}
	else std::cout << "First matrix is not equal to second matrix" << std::endl;

	if (matr1 != matr2) {
		std::cout << "First matrix is not equal to second matrix" << std::endl;
	}
	else std::cout << "First matrix is equal to second matrix" << std::endl;
	}


