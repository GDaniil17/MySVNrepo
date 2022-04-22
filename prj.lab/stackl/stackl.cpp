#include <stackl/stackl.h>
#include <stdexcept>

StackL::StackL(const StackL& obj) {
	if (this != &obj) {
		while (is_empty() == false) {
			this->pop();
		}
		Node* node = obj.head_;
		StackL tmp;
		while (node != nullptr) {
			tmp.push(node->value);
			node = node->next;
		}
		while (tmp.is_empty() == false) {
			this->push(tmp.top());
			tmp.pop();
		}
	}
}

StackL& StackL::operator=(const StackL& obj) {
	if (this != &obj) {
		while (is_empty() == false) {
			this->pop();
		}
		Node* node = obj.head_;
		StackL tmp;
		while (node != nullptr) {
			tmp.push(node->value);
			node = node->next;
		}
		while (tmp.is_empty() == false) {
			this->push(tmp.top());
			tmp.pop();
		}
	}
	return *this;
}
StackL::~StackL() {
	while (is_empty() == false) {
		pop();
	}
}
void StackL::push(const float value) {
	head_ = new Node{ value, head_ };
}
void StackL::pop() {
	if (is_empty()) {
		return;
	}
	Node* del = head_;
	head_ = head_->next;
	delete del;
}
float& StackL::top() {
	if (is_empty()) {
		throw std::logic_error("Stack is empty");
	}
	return head_->value;
}
const float& StackL::top() const {
	if (is_empty()) {
		throw std::logic_error("Stack is empty");
	}
	return head_->value;
}
bool StackL::is_empty() const {
	return head_ == nullptr;
}