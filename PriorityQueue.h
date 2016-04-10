#pragma once
#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

class PriorityQueue
{
	int prioritiesNumber;
	Queue* container;
public:
	explicit PriorityQueue(int = 5);

	bool isAllEmpty() const;

	bool isEmpty(unsigned) const;

	void push(unsigned, const string&);

	string pop(unsigned);

	string top(unsigned) const;

	void print() const;

	~PriorityQueue();
};

