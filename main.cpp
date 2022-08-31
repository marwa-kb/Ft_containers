#include <iostream>
#include <string>
#include "stack.hpp"
#include <stack>
#include <vector>
#include "vector.hpp"
#include "iterator.hpp"
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

		std::cout << BC << "------------" << NC << std::endl;

		NAMESPACE::vector<std::string> test;
		test.push_back("hey");
		test.push_back("how are you");
		test.push_back("man");
		

		NAMESPACE::vector<std::string>::iterator beg = test.begin();
		NAMESPACE::vector<std::string>::iterator end = test.end();

		std::cout << BG << "beginning = " << *beg << NC << std::endl;
		for (; beg != end; beg++)
			std::cout << BY << *beg << " " << NC;
		std::cout << std::endl;


		NAMESPACE::vector<std::string>::const_reverse_iterator rbeg = test.rbegin();
		NAMESPACE::vector<std::string>::const_reverse_iterator rend = test.rend();
		std::cout << BG << "rbeginning = " << *rbeg << NC << std::endl;
		std::cout << BG << "rend = " << *rend << NC << std::endl;
		for (; rbeg != rend; rbeg++)
			std::cout << BY << *rbeg << " " << NC;
		std::cout << std::endl << BC << "------------" << NC << std::endl;

		NAMESPACE::vector<std::string>::iterator iter;
		NAMESPACE::vector<std::string>::const_iterator const_iter;
		const_iter = iter;
		// iter = const_iter;

		NAMESPACE::vector<std::string>::reverse_iterator iter2(iter);
		std::vector<std::string>::reverse_iterator iter3(iter);
		// ft::vector<std::string>::reverse_iterator iter4(iter);
		NAMESPACE::vector<std::string>::const_reverse_iterator const_iter2;
		// const_iter2 = iter2;
		// iter = const_iter;

	}
/*
	if (argv[1] && std::string(argv[1]) == "int")
	{
		 std::cout << std::boolalpha;
  		std::cout << "is_integral:" << std::endl;
  		std::cout << "char: " << NAMESPACE::is_integral<char>::value << std::endl;
  		std::cout << "int: " << NAMESPACE::is_integral<int>::value << std::endl;
  		std::cout << "bool: " << NAMESPACE::is_integral<bool>::value << std::endl;
  		std::cout << "std::vector<int> : " << NAMESPACE::is_integral<std::vector<int> >::value << std::endl;
  		std::cout << "unsigned long: " << NAMESPACE::is_integral<unsigned long>::value << std::endl;
	}
*/
	return (0);
}