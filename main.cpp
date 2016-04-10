#include <iostream>
#include <sstream>

#include "PriorityQueue.h"

using namespace std;

template<class T>

string toString(const T& t)
{
	ostringstream oStream;
	oStream << t;
	return oStream.str();
}

bool test1()
{
	_CrtMemState c1, c2, c3;

	_CrtMemCheckpoint(&c1);

	{
		PriorityQueue test;
	}

	_CrtMemCheckpoint(&c2);

	return !_CrtMemDifference(&c3, &c1, &c2);
}

bool test2()
{
	PriorityQueue qu(3);

	bool passed = (qu.isAllEmpty() ? true : false);

	if (passed)
	{
		qu.push(1, "PROGRAMMING");
		qu.push(1, "DISCRETE_MATHS");

		qu.push(2, "LINEAR ALGEBRA");

		qu.push(5, "PHYSICAL EDUCATION");

		passed = (qu.pop(3) == "PHYSICAL EDUCATION" ? true : false);

		if (passed)
		{
			passed = (qu.pop(2) == "LINEAR ALGEBRA" ? true : false);

			if (passed)
			{
				passed = (qu.pop(1) == "PROGRAMMING" ? true : false);

				if (passed)
				{
					passed = (qu.pop(1) == "DISCRETE_MATHS" ? true : false);
				}
			}
		}
	}

	if (passed)
	{
		passed = (qu.isAllEmpty() ? true : false);
	}

	return passed;
}

bool test3()
{
	PriorityQueue qu(10);

	bool passed = (qu.isAllEmpty() ? true : false);

	if (passed)
	{
		for (size_t i = 0; i < 100; ++i)
		{
			qu.push((i % 10) + 1, toString(i));
		}

		for (size_t i = 0; i < 100; ++i)
		{
			passed = (qu.pop((i % 10) + 1) == toString(i % 10 + 10 * (i / 10)) ? true : false);

			if (!passed)
			{
				break;
			}
		}
	}

	if (passed)
	{
		passed = (qu.isAllEmpty() ? true : false);
	}

	return passed;
}

int main()
{
	if (!test1())
	{
		cout << "Test 1 failed" << endl; 
	}
	else if (!test2())
	{
		cout << "test 2 failed" << endl;
	}
	else if (!test3())
	{
		cout << "Test 3 failed" << endl;
	}
	else
	{
		cout << "All tests succeeded" << endl;
	}

	system("pause");
	return 0;
}