#include <iostream>
#include <string>
#include "stack.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"
#include "colors.h"


int main()
{
	std::cout << UO << "STACK" << NC << std::endl;
	std::vector<int> v;
	v.push_back(4);
	// v.push_back(3);
	// v.push_back(2);
// 
	std::vector<int>::iterator it1 = v.begin();
	std::vector<int>::iterator it2 = v.end();
	std::vector<int>::reverse_iterator r_it1 = v.rbegin();
	std::vector<int>::reverse_iterator r_it2 = v.rend();
	std::cout << "it1 = " << *it1 << std::endl
		<< "it2 = " << *it2 << std::endl
		<< "r_it1 = " << *r_it1 << std::endl
		<< "r_it2 = " << *r_it2 << std::endl;


	// std::stack<int, std::vector<int> > s(v);
	// std::stack<int, std::vector<int> > s2 = s;
	// std::cout << "empty : " << s.empty() << std::endl
	// 	<< "top : " << s.top() << std::endl
	// 	<< "size : " << s.size() << std::endl
	// 	<< "push 5 : ";
	// s.push(55);
	// std::cout << std::endl << "pop" << std::endl;
	// s.pop();
	// std::cout << "== : " << (s == s2 ? "true" : "false") << std::endl
	// 	<< "< : " << (s < s2 ? "true" : "false") << std::endl
	// 	<< "!= : " << (s != s2) << std::endl;
	// std::stack<int, std::vector<int> > essai(v);
	// std::stack<int, std::vector<int> > essai2(v);
	return (0);
}