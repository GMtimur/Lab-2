#include <iostream>
#include <stack.h>

int main()
{
	stack<int>* st = new stack<int>();
	for (int i = 0; i < 10; i++)
	{
		st->push(i);
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << st->pop();
	}
}