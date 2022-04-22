#include <matrixvs/matrixvs.h>
#include <iostream>
#include <vector>

MatrixVs::MatrixVs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) {
	if (col_count <= 0 || row_count <= 0) {
		throw std::logic_error{ "MatrixVs::MatrixVs (col_count < 0 || row_count < 0)" };
	}
	n_col_ = col_count;
	n_row_ = row_count;
	data_.resize(n_row_*n_col_);
	for (int i = 0; i < n_col_ * n_row_; i++) {
		data_[i] = 0.0f;
	}
}

float& MatrixVs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) {
	if (i_row < 0 || i_col < 0 || i_row >= n_row_ || i_col >= n_col_) {
		throw std::logic_error{ "MatrixVs::MatrixVs out of boundaries" };
	}
	return data_[i_col + (colCount() * i_row)];
}
float MatrixVs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const {
	if (i_row < 0 || i_col < 0 || i_row >= n_row_ || i_col >= n_col_) {
		throw std::logic_error{ "MatrixVs::MatrixVs out of boundaries" };
	}
	return data_[i_col + (colCount() * i_row)];
}
MatrixVs& MatrixVs::transpose() noexcept {
	MatrixVs tmp(n_row_, n_col_);
	for (int i = 0; i < n_col_; i++) {
		for (int j = 0; j < n_row_; j++) {
			tmp.at(i, j) = at(j, i);
		}
	}
	*this = tmp;
	return *this;
}
MatrixVs& MatrixVs::multiply(const MatrixVs& rhs) {
	if (n_col_ != rhs.n_row_) {
		throw std::logic_error("MatrixVs::multiply n_col_ != rhs.n_row_");
	}

	MatrixVs tmp(n_row_, rhs.n_col_);
	for (int i = 0; i < n_row_; i++) {
		for (int j = 0; j < rhs.n_col_; j++) {
			for (int k = 0; k < n_col_; k++) {
				tmp.at(i, j) += at(i, k) * rhs.at(k, j);
			}
		}
	}
	*this = tmp;
	return *this;
}
void MatrixVs::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) {
	if (i_first < 0 || i_second < 0 || i_first >= n_row_ || i_second >= n_row_) {
		throw std::logic_error{ "MatrixVs::MatrixVs out of boundaries" };
	}
	float tmp;
	for (int i = 0; i < n_col_; i++) {
		tmp = at(i_first, i);
		at(i_first, i) = at(i_second, i);
		at(i_second, i) = tmp;
	}
}
void MatrixVs::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) {
	if (i_first < 0 || i_second < 0 || i_first >= n_col_ || i_second >= n_col_) {
		throw std::logic_error{ "MatrixVs::MatrixVs out of boundaries" };
	}
	float tmp;
	for (int i = 0; i < n_row_; i++) {
		tmp = at(i, i_first);
		at(i, i_first) = at(i, i_second);
		at(i, i_second) = tmp;
	}
}