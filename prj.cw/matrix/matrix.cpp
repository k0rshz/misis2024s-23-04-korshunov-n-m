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

