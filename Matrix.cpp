#include "Matrix.h"
#include <cstdlib>

Matrix::Matrix(unsigned int length, unsigned int width) : m(length), n(width) {
	data = new int* [m];
	for (unsigned int i = 0; i < m; ++i) {
		data[i] = new int[n];
	}
}

Matrix::~Matrix() {
	for (unsigned int i = 0; i < m; ++i) {
		delete[] data[i];
	}
	delete[] data;
}

void Matrix::RandFill() {
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			data[i][j] = rand() % 10;
		}
	}
}

int* Matrix::operator[](int index) {
	return data[index];
}


Matrix& Matrix::operator+=(const Matrix& other) {
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			data[i][j] += other.data[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& other) {
	Matrix rez(m, n);
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			rez.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return rez;
}


Matrix& Matrix::operator-=(const Matrix& other) {
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix& other) {
	Matrix rez(m, n);
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			rez.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return rez;
}


Matrix& Matrix::operator*=(const Matrix& other) {
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			data[i][j] *= other.data[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& other) {
	Matrix rez(m, n);
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			rez.data[i][j] = data[i][j] * other.data[i][j];
		}
	}
	return rez;
}


bool Matrix::operator==(const Matrix& other)
{
	if (m != other.m || n != other.n)
		return false;
	for (unsigned int i = 0; i < m; ++i) {
		for (unsigned int j = 0; j < n; ++j) {
			if (data[i][j] != other.data[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& other)
{
	return !(*this == other);
}


std::ostream& operator <<(std::ostream& os, const Matrix& matrix)
{
	for (unsigned int i = 0; i < matrix.m; ++i) {
		for (unsigned int j = 0; j < matrix.n; ++j)
		{
			os << matrix.data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}