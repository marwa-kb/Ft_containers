#include <iostream>
#include <string>
#include "stack.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"
#include "colors.h"


int main()
{
/*
	std::cout << UO << "STACK" << NC << std::endl;
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	NAMESPACE::stack<int, std::vector<int> > s(v);
	NAMESPACE::stack<int, std::vector<int> > s2 = s;
	std::cout << "empty : " << s.empty() << std::endl
		<< "top : " << s.top() << std::endl
		<< "size : " << s.size() << std::endl
		<< "push 5 : ";
	s.push(55);
	std::cout << std::endl << "pop : ";
	s.pop();
	std::cout << std::endl
		<< "== : " << (s == s2 ? "true" : "false") << std::endl
		<< "< : " << (s < s2 ? "true" : "false") << std::endl
		<< "!= : " << (s != s2) << std::endl;
	std::stack<int, std::vector<int> > essai(v);
	std::stack<int, std::vector<int> > essai2(v);
*/

	std::cout << std::endl << UO << "VECTOR" << NC << std::endl;
	
	NAMESPACE::vector<int> v2;
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.clear();
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.reserve(3);
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.push_back(74);
	v2.push_back(74);
	v2.push_back(74);
	std::cout << MA << "size = " << v2.size() << NC << std::endl;
	std::cout << MA << "capacity = " << v2.capacity() << NC << std::endl;
	v2.clear();
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	try
	{
		v2.reserve(v2.max_size() + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

/*
	NAMESPACE::vector<int> v1(3, 41);
	std::cout << "size = " << v1.size() << std::endl;
	v1.push_back(4);
	std::cout << "size = " << v1.size() << std::endl;
	v1.push_back(3);
	std::cout << "size = " << v1.size() << std::endl;
	v1.push_back(2);
	std::cout << "size = " << v1.size() << std::endl;
	int size = v1.size();
	std::cout << "size = " << size << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << "value = " << v1[i] << std::endl;
	v1.pop_back();
	v1.pop_back();
	std::cout << "capacity = " << v1.capacity() << std::endl;
	size = v1.size();
	std::cout << "size = " << size << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << "value = " << v1[i] << std::endl;
*/
/*	NAMESPACE::vector<int> v2 = v;
	v2.push_back(5);
	int size2 = v2.size();
	std::cout << "size2 = " << size2 << std::endl;
	for (int j = 0; j < size2; j++)
		std::cout << "value2 = " << v2[j] << std::endl;
	std::cout << "value2 front = " << v2.front() << std::endl;
	std::cout << "value2 back = " << v2.back() << std::endl;
	std::cout << "value2 data = " << v2.data() << std::endl;
	*/
	return (0);
}