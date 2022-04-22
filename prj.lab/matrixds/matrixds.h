#pragma once
#ifndef MATRIXDS_MATRIXDS_H_20211020
#define MATRIXDS_MATRIXDS_H_20211020

#include <cstddef>
#include <vector>

class MatrixDs {
	public:
		MatrixDs() = default;
		MatrixDs(const MatrixDs&) = default;
		MatrixDs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
		~MatrixDs() = default;
		MatrixDs& operator=(const MatrixDs&) = default;

		std::ptrdiff_t rowCount() const noexcept { return n_row_;}
		std::ptrdiff_t colCount() const noexcept { return n_col_;}
		float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col);
		float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const;
		MatrixDs& transpose() noexcept;
		MatrixDs& multiply(const MatrixDs& rhs);
		void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);
		void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);
	private:
		std::ptrdiff_t n_row_{0};
		std::ptrdiff_t n_col_{0};
		std::vector<std::vector<float>> data_;
};

#endif
