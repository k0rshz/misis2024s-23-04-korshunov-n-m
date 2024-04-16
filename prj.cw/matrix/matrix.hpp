#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <vector>

class Matrix {
public:
	Matrix() = default;
	Matrix(int rows, int cols);
	~Matrix() = default;
	Matrix(const Matrix&) = default;
	Matrix& operator=(const Matrix&) = default;
	double& at(int row, int col);
	const double& at(int row, int col) const;

	void multi(double a);
	void transpose();
	Matrix getMinor(int row, int col);
	double determinant();
	Matrix multiply(const Matrix& other);
	Matrix degree(int a);
	void swapRows(int a, int b);
	void print();
	void clear();
	int rank();
	void addRowMultiple(int a, int b, double k);
	void inverse();
	Matrix identity();
private:
	std::vector<std::vector<double>> data_{ {} };
	int rows_ = 0;
	int cols_ = 0;
};

#endif
