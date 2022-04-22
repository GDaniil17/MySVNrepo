#include <queuea/queuea.h>
#include <iostream>
#include <sstream>

int main() {
	QueueA q;
	q.push(11.0f);
	std::cout << q.top() << "\n";
	q.push(21.0f);
	std::cout << q.top() << "\n";
	q.push(31.0f);
	std::cout << q.top() << "\n";
	q.pop();
	std::cout << q.top() << "\n";
	q.pop();
	std::cout << q.top() << "\n";
	q.pop();
	std::cout << q.is_empty() << "\n";
}