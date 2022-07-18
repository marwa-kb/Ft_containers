#include <iostream>
#include <string>
#include "stack.hpp"
#include <vector>
#include "vector.hpp"


int main()
{
	// std::cout << "STACK" << std::endl;
	// std::vector<int> v;
	// v.push_back(4);
	// v.push_back(3);
	// v.push_back(2);
	// ft::stack<int> s(v);
	// ft::stack<int> s2 = s;
	// std::cout << "empty : " << s.empty() << std::endl
	// 	<< "top : " << s.top() << std::endl
	// 	<< "size : " << s.size() << std::endl
	// 	<< "push 5 : ";
	// s.push(55);
	// std::cout << std::endl << "pop : ";
	// s.pop();
	// std::cout << std::endl
	// 	<< "== : " << (s == s2 ? "true" : "false") << std::endl
	// 	<< "< : " << (s < s2 ? "true" : "false") << std::endl
	// 	<< "!= : " << (s != s2) << std::endl;
	// std::stack<int, std::vector<int> > essai(v);
	// std::stack<int, std::vector<int> > essai2(v);


	std::cout << std::endl << "VECTOR" << std::endl;
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	// std::cout << "allocator = " << v.get_allocator() << std::endl;
	return (0);
}