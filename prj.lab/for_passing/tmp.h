#pragma once
#ifndef TMP_TMP_H
#define TMP_TMP_H
#include <vector>

class QueueL {
public:
	QueueL() = default;
	QueueL(const QueueL& q);
	~QueueL();
	void pop();
	void push();
	float& top();
	const float top() const;
	bool is_empty();

private:
	ptrdiff_t i_tail{ -1 };
	ptrdiff_t i_head{ -1 };
	ptrdiff_t cap{ 0 };
	std::vector<float>

};

#endif