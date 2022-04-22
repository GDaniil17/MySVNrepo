#include <matrixds/matrixds.h>
#include <iostream>
#include <vector>

MatrixDs::MatrixDs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) {
	if (col_count <= 0 || row_count <= 0) {
		throw std::logic_error{ "MatrixDs::MatrixDs (col_count < 0 || row_count < 0)" };
	}
	n_col_ = col_count;
	n_row_ = row_count;
	data_ = std::vector<std::vector<float>>(n_row_, std::vector<float>(n_col_, 0.0f));
}
/*
MatrixDs& MatrixDs::operator=(const MatrixDs& newVal) {
	if (this != &newVal) {
		data_.clear();
		n_row_ = newVal.rowCount();
		n_col_ = newVal.colCount();
		data_ = std::vector<std::vector<float>>(n_row_, std::vector<float>(n_col_, 0.0f));
		for (int i = 0; i < n_row_; i++) {
			for (int j = 0; j < n_col_; j++) {
				data_[i][j] = newVal.at(i, j);
			}
		}
	}
	return *this;
}
*/

float& MatrixDs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) {
	if (i_row < 0 || i_col < 0 || i_row >= n_row_ || i_col >= n_col_) {
		throw std::logic_error{ "MatrixDs::MatrixDs out of boundaries" };
	}
	return data_[i_row][i_col];
}
float MatrixDs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const {
	if (i_row < 0 || i_col < 0 || i_row >= n_row_ || i_col >= n_col_) {
		throw std::logic_error{ "MatrixDs::MatrixDs out of boundaries" };
	}
	return data_[i_row][i_col];
}
MatrixDs& MatrixDs::transpose() noexcept {
	MatrixDs tmp(n_row_, n_col_);
	for (int i = 0; i < n_col_; i++) {
		for (int j = 0; j < n_row_; j++) {
			tmp.at(i, j) = at(j, i);
		}
	}
	*this = tmp;
	return *this;
}
MatrixDs& MatrixDs::multiply(const MatrixDs& rhs) {
	if (n_col_ != rhs.n_row_) {
		throw std::logic_error("MatrixDs::multiply n_col_ != rhs.n_row_");
	}

	MatrixDs tmp(rhs.n_col_, n_row_);
	for (int i = 0; i < tmp.rowCount(); i++) { //3
		for (int j = 0; j < tmp.colCount(); j++) { //3
			for (int k = 0; k < n_col_; k++) {
				tmp.at(i, j) += at(i, k) * rhs.at(k, j);
			}
		}
	}
	*this = tmp;
	return *this;
}

void MatrixDs::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) {
	if (i_first < 0 || i_second < 0 || i_first >= n_row_ || i_second >= n_row_) {
		throw std::logic_error{ "MatrixDs::MatrixDs out of boundaries" };
	}
	float tmp;
	for (int i = 0; i < n_col_; i++) {
		tmp = at(i_first, i);
		at(i_first, i) = at(i_second, i);
		at(i_second, i) = tmp;
	}
}
void MatrixDs::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) {
	if (i_first < 0 || i_second < 0 || i_first >= n_col_ || i_second >= n_col_) {
		throw std::logic_error{ "MatrixDs::MatrixDs out of boundaries" };
	}
	float tmp;
	for (int i = 0; i < n_row_; i++) {
		tmp = at(i, i_first);
		at(i, i_first) = at(i, i_second);
		at(i, i_second) = tmp;
	}
}