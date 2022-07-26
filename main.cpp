#include <iostream>
#include <string>
#include "stack.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"


int main()
{
/*
	std::cout << "STACK" << std::endl;
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

	std::cout << std::endl << "VECTOR" << std::endl;
	NAMESPACE::vector<int> v(3, 41);
	//v.push_back(4);
	//v.push_back(3);
	//v.push_back(2);
	std::cout << "empty ? " << v.empty() << std::endl;
	int size = v.size();
	std::cout << "size = " << size << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << "value = " << v[i] << std::endl;
		
	NAMESPACE::vector<int> v2 = v;
	int size2 = v2.size();
	std::cout << "size2 = " << size2 << std::endl;
	for (int j = 0; j < size2; j++)
		std::cout << "value2 = " << v2[j] << std::endl;
	std::cout << "value2 front = " << v2.front() << std::endl;
	std::cout << "value2 back = " << v2.back() << std::endl;
	std::cout << "value2 data = " << v2.data() << std::endl;
		
	
	return (0);
}