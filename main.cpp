#include <iostream>
#include <string>
#include "stack.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"
#include "colors.h"


int main(int argc, char *argv[])
{
	if (argc == 1 || (argv[1] && std::string(argv[1]) == "stack"))
	{
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
		std::cout << std::endl;
	}

	if (argc == 1 || (argv[1] && std::string(argv[1]) == "vector"))
	{
		std::cout << UO << "VECTOR" << NC << std::endl;
		
		NAMESPACE::vector<int> v2;
		std::cout << GN << "size = " << v2.size() << NC << std::endl;
		std::cout << GN << "capacity = " << v2.capacity() << NC << std::endl;
		v2.reserve(3);
		std::cout << "size = " << v2.size() << std::endl;
		std::cout << "capacity = " << v2.capacity() << std::endl;
		v2.push_back(74);
		v2.push_back(74);
		v2.push_back(74);
		v2.push_back(89);
		int size = v2.size();
		for (int i = 0; i < size; i++)
			std::cout << YE << v2[i] << NC << std::endl;
		std::cout << MA << "size = " << v2.size() << NC << std::endl;
		std::cout << MA << "capacity = " << v2.capacity() << NC << std::endl;
		v2.assign(5, 10);
		v2.push_back(89);
		size = v2.size();
		for (int j = 0; j < size; j++)
			std::cout << YE << v2.at(j) << NC << std::endl;
		std::cout << MA << "size = " << v2.size() << NC << std::endl;
		std::cout << MA << "capacity = " << v2.capacity() << NC << std::endl;
		v2.push_back(89);
		v2.resize(101, 12);
		size = v2.size();
		std::cout << RE << "size = " << v2.size() << NC << std::endl;
		std::cout << RE << "capacity = " << v2.capacity() << NC << std::endl;
		

		NAMESPACE::vector<int> v1(3, 41);
		std::cout << "size = " << v1.size() << std::endl;
		v1.push_back(4);
		std::cout << "size = " << v1.size() << std::endl;
		v1.push_back(3);
		std::cout << "size = " << v1.size() << std::endl;
		v1.push_back(2);
		std::cout << "size = " << v1.size() << std::endl;
		int size1 = v1.size();
		std::cout << "size = " << size1 << std::endl;
		for (int i = 0; i < size1; i++)
			std::cout << "value = " << v1[i] << std::endl;
		v1.pop_back();
		v1.pop_back();
		std::cout << "capacity = " << v1.capacity() << std::endl;
		size1 = v1.size();
		std::cout << "size = " << size1 << std::endl;
		for (int i = 0; i < size1; i++)
			std::cout << "value = " << v1[i] << std::endl;

		std::cout << (v1 == v2 ? "same" : "different") << std::endl;
		std::cout << (v1 != v1 ? "not same" : "not different") << std::endl;

		NAMESPACE::vector<int>::iterator beg = v1.begin();
		NAMESPACE::vector<int>::iterator end = v1.end();
		std::cout << BG << "beginning = " << *beg << NC << std::endl;
		std::cout << BG << "end = " << *end << NC << std::endl;
		for (; beg != end; beg++)
			std::cout << BY << *beg << " " << NC;
		std::cout << std::endl;
	}

	return (0);
}