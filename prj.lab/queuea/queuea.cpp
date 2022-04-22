#include <iostream>
#include <queuea/queuea.h>

QueueA::QueueA(const QueueA& q) {
	capacity_ = q.capacity_;
	i_head_ = q.i_head_;
	i_tail_ = q.i_tail_;
	data_ = new float[capacity_];
	std::copy(q.data_, q.data_ + q.capacity_, data_);
}
QueueA& QueueA::operator=(const QueueA& q) {
	if (this != &q) {
		capacity_ = q.capacity_;
		i_head_ = q.i_head_;
		i_tail_ = q.i_tail_;
		data_ = new float[capacity_];
		std::copy(q.data_, q.data_ + q.capacity_, data_);
	}
	return *this;
}
bool QueueA::is_empty() const {
	return capacity_ == 0;
}
void QueueA::push(const float val) {
	if (is_empty()) {
		i_tail_ = 0;
	}
	i_head_ += 1;
	capacity_ += 1;
	float* newdata = new float[capacity_];
	std::copy(data_, data_ + capacity_ - 1, newdata);
	newdata[i_head_] = val;
	delete[] data_;
	data_ = newdata;
}
float& QueueA::top() {
	if (is_empty()) {
		throw std::logic_error("Nothing at the top!");
	}
	return data_[i_tail_];
}
const float& QueueA::top() const {
	if (is_empty()) {
		throw std::logic_error("Nothing at the top!");
	}
	return data_[i_tail_];
}

void QueueA::pop() {
	if (!is_empty()) {
		capacity_ -= 1;
		i_head_ -= 1;
		if (capacity_ == 0) {
			i_tail_ = -1;
			data_ = nullptr;
		}
		else {
			float* newData = new float[capacity_];
			std::copy(data_ + 1, data_ + capacity_ + 1, newData);
			delete[] data_;
			data_ = newData;
		}
	}
}