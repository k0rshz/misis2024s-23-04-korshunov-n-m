#include "matrix/matrix.hpp"

Matrix::Matrix(int rows, int cols) {
	std::vector<std::vector<double>> a(rows, std::vector<double>(cols));
	data_ = a;
	rows_ = rows;
	cols_ = cols;
}

double& Matrix::at(int row, int col) {
	if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
		throw std::out_of_range("Index out of range");
	}
	return data_[row][col];
}

const double& Matrix::at(int row, int col) const {
	if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
		throw std::out_of_range("Index out of range");
	}
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

Matrix Matrix::multiply(const Matrix& other) {
	if (cols_ != other.rows_) {
		throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix");
	}

	Matrix result(rows_, other.cols_);

	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < other.cols_; ++j) {
			double sum = 0;
			for (int k = 0; k < cols_; ++k) {
				sum += data_[i][k] * other.data_[k][j];
			}
			result.at(i, j) = sum;
		}
	}

	return result;
}

Matrix Matrix::degree(int a) {
	Matrix res(*this);
	Matrix temp(res);
	for (int i = 0; i < a - 1; ++i) {
		res = res.multiply(temp);
	}
	return res;
}

void Matrix::swapRows(int a, int b) {
	double c;
	for (int i = 0; i < cols_; ++i) {
		c = data_[a][i];
		data_[a][i] = data_[b][i];
		data_[b][i] = c;
	}
}

void Matrix::print() {
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			std::cout << data_[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Matrix::clear() {
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			data_[i][j] = 0;
		}
		std::cout << "\n";
	}
}

void Matrix::addRowMultiple(int a, int b, double k) {
	if (a < 0 || a >= rows_ || b < 0 || b >= rows_) {
		throw std::out_of_range("Row index out of range");
	}
	for (int i = 0; i < cols_; ++i) {
		data_[b][i] += data_[a][i] * k;
	}
}

//int Matrix::rank() {
//	Matrix temp(*this);
//	int rank = 0;
//	for (int i = 0; i < temp.cols_; ++i) {
//		bool nZero = false;
//		for (int j = rank; j < temp.rows_; ++j) {
//			if (std::abs(temp.data_[j][i]) > 1e-9) {
//				nZero = true;
//				if (j != rank) {
//					temp.swapRows(j, rank);
//				}
//				break;
//			}
//		}
//		if (nZero) {
//			for (int j = rank + 1; j < temp.rows_; ++j) { 
//				if (std::abs(temp.data_[j][i]) > 1e-9) {
//					double k = -temp.data_[j][i] / temp.data_[rank][i];
//					temp.addRowMultiple(j, rank, k);
//				}
//			}
//			rank += 1;
//		}
//	}
//	return rank;
//}

Matrix Matrix::identity() {
	Matrix res(rows_, cols_);
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			if (i == j) {
				res.at(i, j) = 1;
			}
		}
	}
	return res;
}

void Matrix::inverse() {
	if (rows_ != cols_) {
		throw std::invalid_argument("Inverse can only be calculated for a square matrix");
	}
	Matrix temp(*this);
	Matrix identity = Matrix::identity();
	for (int i = 0; i < rows_; ++i) {
		double a = data_[i][i];
		if (a == 0) {
			int idx = -1;
			for (int j = i + 1; j < rows_; ++j) {
				if (data_[j][i] != 0) {
					idx = j;
					break;
				}
			}
			if (idx == -1) {
				throw std::runtime_error("Matrix is not invertible");
			}
			swapRows(i, idx);
			identity.swapRows(i, idx);
			a = data_[i][i];
		}
		for (int j = 0; j < cols_; ++j) {
			data_[i][j] /= a;
			identity.data_[i][j] /= a;
		}
		for (int j = 0; j < rows_; ++j) {
			if (j != i) {
				double k = data_[j][i];
				for (int l = 0; l < cols_; ++l) {
					data_[j][l] -= k * data_[i][l];
					identity.data_[j][l] -= k * identity.data_[i][l];
				}
			}
		}
	}
	for (int i = 0; i < rows_; ++i) {
		for (int j = 0; j < cols_; ++j) {
			data_[i][j] = identity.data_[i][j];
		}
	}

}

