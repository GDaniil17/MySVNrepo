#ifndef ARRAYD_ARRAYD_H_2021
#define ARRAYD_ARRAYD_H_2021
#include <cstddef>

class ArrayD {
	public:
		ArrayD() = default;
		ArrayD(const ArrayD& arr);
		explicit ArrayD(const std::ptrdiff_t size);
		ArrayD& operator=(const ArrayD& rhs);
		~ArrayD() { delete[] data_; }
		std::ptrdiff_t size() const { return size_; }
		float& operator[](const std::ptrdiff_t i);
		const float& operator[](const std::ptrdiff_t i) const;
		void resize(const std::ptrdiff_t size);
	private:
		std::ptrdiff_t capacity_{ 0 };
		std::ptrdiff_t size_{ 0 };
		float* data_{ nullptr };
};

#endif