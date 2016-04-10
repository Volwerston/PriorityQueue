#pragma once

using namespace std;

class Queue
{
	size_t capacity;
	size_t position;
	string* array;
public:
	explicit Queue(size_t = 10);

	bool isEmpty() const;

	void push(const string&);

	string pop();

	string top() const;

	void print() const;

	~Queue();
};