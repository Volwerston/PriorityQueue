#pragma once

#include <iostream>
#include <string>

#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue(int _n)
	: prioritiesNumber(_n)
{
	container = new Queue[prioritiesNumber];
}

bool PriorityQueue::isAllEmpty() const
{
	bool allEmpty = true;

	for (size_t i = 0; i < prioritiesNumber; ++i)
	{
		if (!container[i].isEmpty())
		{
			allEmpty = false;
			break;
		}
	}

	return allEmpty;
}

bool PriorityQueue::isEmpty(unsigned pr) const
{
	bool toReturn = false;

	if (pr >= prioritiesNumber)
	{
		toReturn = container[prioritiesNumber - 1].isEmpty();
	}
	else
	{
		toReturn = container[pr].isEmpty();
	}

	return toReturn;;
}

void PriorityQueue::push(unsigned pr, const string& data)
{
	if (pr >= prioritiesNumber)
	{
		container[prioritiesNumber - 1].push(data);
	}
	else
	{
		container[pr - 1].push(data);
	}
}

string PriorityQueue::pop(unsigned pr)
{
	string toReturn = "";

	if (pr >= prioritiesNumber)
	{
		toReturn = container[prioritiesNumber - 1].pop();
	}
	else
	{
		toReturn = container[pr - 1].pop();
	}

	return toReturn;
}

string PriorityQueue::top(unsigned pr) const
{
	string toReturn = "";

	if (pr >= prioritiesNumber)
	{
		toReturn = container[prioritiesNumber - 1].top();
	}
	else
	{
		toReturn = container[pr - 1].top();
	}

	return toReturn;
}

void PriorityQueue::print() const
{
	for (size_t i = 0; i < prioritiesNumber; ++i)
	{
		container[i].print();
	}

	cout << endl;
}

PriorityQueue::~PriorityQueue()
{
	delete[] container;
}