#include<iostream>
#include <vector>

class QA {
public:
	QA() = default;
	~QA() {
		delete[] data_;
	}
	void push(const float val) {
		cap++;
		if (tail == -1) {
			tail = 0;
			head = 0;
		}
		float* tmp = new float[cap] {0.0f};
		for (ptrdiff_t i = head; i < tail; i++) {
			*(tmp + i) = this->data_[i];
		}
		tmp[cap-1] = val;
		delete[] data_;
		data_ = tmp;
		tail++;
	}

	const float& top() {
		if (is_empty()) {
			throw std::out_of_range("Top is not defined!");
		}
		return data_[head];
	}

	void pop() {
		if (is_empty()) {
			return;
		}
		float* tmp = new float[cap - 1];
		for (ptrdiff_t i = head; i < tail-1; i++) {
			*(tmp + i) = data_[i+1];
		}
		delete[] data_;
		data_ = tmp;
		cap--;
		if (cap == 0) {
			tail = -1;
			head = -1;
			data_ = nullptr;
		}
		else {
			tail--;
		}

	}

	bool is_empty() {
		return cap == 0;
	}
private:
	float* data_ = nullptr;
	ptrdiff_t tail{ -1 };
	ptrdiff_t head{ -1 };
	ptrdiff_t cap{ 0 };
};

int main()
{
	QA q = QA();
	std::cout <<q.is_empty() << "\n";
	q.push(1.1f);
	std::cout << q.top() << "\n";
	q.push(2.1f);
	std::cout << q.top() << "\n";
	q.pop();
	std::cout << q.top() << "\n";
	q.pop();
	std::cout << q.is_empty() << "\n";

}