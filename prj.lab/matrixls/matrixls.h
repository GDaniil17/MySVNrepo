#pragma once
#ifndef MATRIXLS_MATRIXLS_H_20211020
#define MATRIXLS_MATRIXLS_H_20211020

#include <cstddef>
#include <vector>

class MatrixLs {
public:
	MatrixLs() = default;
	MatrixLs(const MatrixLs& obj) = default;
	MatrixLs(const std::ptrdiff_t n_col, const std::ptrdiff_t n_row);
	MatrixLs& operator=(const MatrixLs& obj) = default;
	~MatrixLs() { begin_.clear(), data_.clear(); }

	std::ptrdiff_t rowCount() const noexcept { return n_row_; }
	std::ptrdiff_t colCount() const noexcept { return n_col_; }
	float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col);
	float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const;
	MatrixLs& transpose() noexcept;
	MatrixLs& multiply(const MatrixLs& rhs);
	void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);
	void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);

private:
	std::ptrdiff_t n_row_{ 0 };
	std::ptrdiff_t n_col_{ 0 };
	std::vector<float> data_;
	std::vector<int> begin_;
};

#endif
