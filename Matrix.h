#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
class Matrix
{
private:
	int** data;
	unsigned int m;
	unsigned int n;

public:
	Matrix(unsigned int length, unsigned int width);
	~Matrix();

	void RandFill();
	int* operator[] (int index);

	Matrix& operator+=(const Matrix& other);
	Matrix operator+(const Matrix& other);

	Matrix& operator-=(const Matrix& other);
	Matrix operator-(const Matrix& other);

	Matrix& operator*=(const Matrix& other);
	Matrix operator*(const Matrix& other);

	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);

	friend std::ostream&
		operator<<(std::ostream& os, const Matrix& matrix);
};
#endif