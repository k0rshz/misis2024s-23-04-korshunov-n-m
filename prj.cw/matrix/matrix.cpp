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
	if (abs(det) < 1e-9) {
		return 0;
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

void Matrix::degree(int a) {
	Matrix res(*this);
	Matrix temp(res);
	for (int i = 0; i < a - 1; ++i) {
		res = res.multiply(temp);
	}
	data_ = res.data_;
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

int Matrix::rank() {
	Matrix temp = *this;
	int rank = std::min(cols_, rows_);
	for (int row = 0; row < rank; ++row) {
		if (temp.data_[row][row] == 0) {
			bool found = false;
			for (int i = row + 1; i < temp.rows_; ++i) {
				if (temp.data_[i][row] != 0) {
					temp.swapRows(row, i);
					found = true;
					break;
				}
			}
			if (!found) {
				rank -= 1;
				row -= 1;
				continue;
			}
		}
		for (int i = 0; i < temp.rows_; ++i) {
			if (i != row) {
				double factor = temp.data_[i][row] / temp.data_[row][row];
				for (int j = row; j < temp.cols_; ++j) {
					temp.data_[i][j] -= temp.data_[row][j] * factor;
				}
			}
		}
	}

	int rank1 = 0;
	for (int i = 0; i < temp.rows_; ++i) {
		bool isZero = true;
		for (int j = 0; j < temp.cols_; ++j) {
			if (abs(temp.data_[i][j]) > 1e-9) {
				isZero = false;
				break;
			}
		}
		if (!isZero) {
			rank1 += 1;
		}
	}

	return rank1;
}

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

void Matrix::resize(int i, int j) {
	if (i < 1 || j < 1) {
		throw std::out_of_range("Index out of range");
	}
	else {
		Matrix a(i, j);
		for (int n = 0; n < i && n < rows_; ++n) {
			for (int m = 0; m < j && m < cols_; ++m) {
				a.at(n, m) = data_[n][m];
			}
		}
		data_ = a.data_;
		rows_ = i;
		cols_ = j;
	}
}
