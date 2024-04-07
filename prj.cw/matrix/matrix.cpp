#include "matrix/matrix.hpp"

Matrix::Matrix(int rows, int cols) {
	std::vector<std::vector<double>> a(rows, std::vector<double>(cols));
	data_ = a;
	rows_ = rows;
	cols_ = cols;
}

double& Matrix::at(int row, int col) {
	return data_[row][col];
}

const double& Matrix::at(int row, int col) const {
	return data_[row][col];
}

void Matrix::multi(double a) {
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			data_[i][j] *= a;
		}
	}
}

void Matrix::transpose() {
	Matrix c(cols_, rows_);
	for (int i = 0; i < cols_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			c.at(i, j) = data_[j][i];
		}
	}
	data_ = c.data_;
	cols_ = c.cols_;
	rows_ = c.rows_;
}

Matrix Matrix::getMinor(int row, int col) {
	Matrix minor(rows_ - 1, cols_ - 1);
	int minorRow = 0;
	int minorCol = 0;
	for (int i = 0; i < rows_; ++i) {
		if (i == row) {
			continue;
		}
		minorCol = 0;
		for (int j = 0; j < cols_; ++j) {
			if (j == col) {
				continue;
			}
			minor.at(minorRow, minorCol) = data_[i][j];
			minorCol += 1;
		}
		minorRow += 1;
	}
	return minor;
}

double Matrix::determinant() {
	if (rows_ != cols_) {
		throw std::runtime_error("Determinant can only be calculated for a square matrix");
	}
	if (rows_ == 1) {
		return data_[0][0];
	}
	double det = 0;
	int sign = 1;
	Matrix temp(rows_ - 1, cols_ - 1);
	for (int i = 0; i < cols_; ++i) {
		temp = getMinor(0, i);
		det += sign * data_[0][i] * temp.determinant();
		sign = -sign;
	}
	return det;
}