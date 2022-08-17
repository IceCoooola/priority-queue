#include"priority_queue.h"
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	IceCola::priority_queue<int> p;
	p.push(1);
	p.push(3);
	p.push(5);
	p.push(8);
	while (!p.empty())
	{
		std::cout << p.top()<<std::endl;
		p.pop();
	}

	std::cout << std::endl;

	std::vector<int> v = { 6, 9 ,8 , 0, 77,-6 };
	IceCola::priority_queue<int> pp(v.begin(), v.end());
	while (!pp.empty())
	{
		std::cout << pp.top() << std::endl;
		pp.pop();
	}
	return 0;
}
