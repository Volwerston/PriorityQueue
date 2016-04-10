#pragma once

#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

Queue::Queue(size_t _cap)
	: capacity(_cap),
	position(0)
{
	array = new string[capacity];
}

bool Queue::isEmpty() const
{
	return position == 0;
}

void Queue::push(const string& arg)
{
	if (position == capacity)
	{
		string* buffer = new string[2 * capacity];
		for (size_t i = 0; i < position; ++i)
		{
			buffer[i] = array[i];
		}
		capacity *= 2;
		delete[] array;
		array = buffer;
	}
	array[position++] = arg;
}

string Queue::pop()
{
	string toReturn = "";

	bool empty = false;
	if (isEmpty())
	{
		cout << "The queue is empty" << endl;
		empty = true;
	}
	if (!empty)
	{
		toReturn = array[0];

		for (size_t i = 0; i < position - 1; ++i)
		{
			array[i] = array[i + 1];
		}
		--position;
	}

	return toReturn;
}

string Queue::top() const
{
	string toReturn = "";

	if (!isEmpty())
	{
		toReturn = array[0];
	}

	return toReturn;
}

void Queue::print() const
{
	bool empty = false;
	if (isEmpty())
	{
		cout << "The queue is empty" << endl;
		empty = true;
	}
	if (!empty)
	{
		for (size_t i = 0; i < position; ++i)
		{
			cout << array[i] << "   ";
		}
		cout << endl;
	}
}

Queue::~Queue()
{
	delete[] array;
}