#include <arrayd/arrayd.h>
#include <iostream>

ArrayD::ArrayD(const ArrayD& arr) {
	capacity_ = arr.size()*2+1;
	size_ = arr.size();
	delete[] data_;
	data_ = new float[capacity_];
	for (ptrdiff_t i = 0; i < size_; i++) {
		*(data_+i) = arr[i];
	}
}
ArrayD::ArrayD(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::logic_error{ "ArrayD::ArrayD(const std::ptrdiff_t size)" };
	}
	capacity_ = size*2+1;
	size_ = size;
	delete[] data_;
	data_ = new float[capacity_];
	for (ptrdiff_t i = 0; i < size; i++) {
		*(data_ + i) = 0.0f;
	}

}

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
	if (&rhs != this) {
		resize(rhs.size_);
		capacity_ = size_;

		for (int i = 0; i < size_; i++)
		{
			data_[i] = rhs[i];
		}
	}
	return *this;
}

float& ArrayD::operator[](const std::ptrdiff_t i) {
	if (i < 0 || i >= size_) {
		throw std::logic_error{ "ArrayD::operator[]" };
	}
	return data_[i];
}
const float& ArrayD::operator[](const std::ptrdiff_t i) const {
	if (i < 0 || i >= size_) {
		throw std::logic_error{ "ArrayD::operator[]" };
	}
	return data_[i];
}
void ArrayD::resize(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::logic_error{ "ArrayD::resize()" };
	}
	if (size > capacity_) {
		float* tmp = new float[size];

		for (ptrdiff_t i = 0; i < size_; i++) {
			*(tmp + i) = data_[i];
		}
		delete data_;
		capacity_ = size*2+1;
		data_ = new float[capacity_];
		for (ptrdiff_t i = 0; i < size_; i++) {
			*(data_ + i) = *(tmp + i);
		}
		delete[] tmp;
	}
	for (ptrdiff_t i = size_; i < size; ++i)
		*(data_ + i) = 0.0f;
	size_ = size;
}