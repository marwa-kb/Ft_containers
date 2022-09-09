#include "tests.h"

//use std:: or ft::vector in examples ? ->i think i should use std

void stack_tests()
{
	std::cout << BW << "                        _______" << NC << std::endl;
	std::cout << BW << "―――――――――――――――――――――――| STACK |――――――――――――――――――――――" << NC << std::endl;
	std::cout << BW << "                        ‾‾‾‾‾‾‾" << NC << std::endl;

	std::cout << MA << "Container used : vector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)" << NC << std::endl;
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);



	/********* testing constructors *********/
	std::cout << GN << "\nCreation of stack0 with ft::vector as default container" << NC << std::endl;
	NAMESPACE::stack<float> stack0;
	std::cout << GN << "Creation of stack1 via default (container) constructor" << NC << std::endl;
	NAMESPACE::stack<int, std::vector<int> > stack1(v1);
	std::cout << GN << "Creation of stack2 via copy constructor" << NC << std::endl;
	NAMESPACE::stack<int, std::vector<int> > stack2(stack1);
	std::cout << CY << "Creation of stack3 via assignation operator" << NC << std::endl;
	NAMESPACE::stack<int, std::vector<int> > stack3 = stack2;
	

	/******* testing member functions *******
	* 
	*		top, empty, size, push, pop
	*
	******** ************************ *******/

	stack0.push(45.18f);
	std::cout << YE << "\nstack0 push \"45.18\"" << NC << std::endl
		<< YE << "stack0 top : " << NC << stack0.top() << std::endl;
	std::cout << YE << "stack1 empty : " << NC << (stack1.empty() ? "true" : "false") << std::endl
		<< YE << "stack1 size : " << NC << stack1.size() << std::endl
		<< YE << "stack1 top : " << NC << stack1.top() << std::endl
		<< YE << "stack1 push \"11\"" << NC << std::endl;
	stack1.push(11);
	std::cout << YE << "stack1 size : " << NC << stack1.size() << std::endl
		<< YE << "stack1 top : " << NC << stack1.top() << std::endl;
	std::cout << YE << "stack1 pop (x2)" << NC << std::endl;
	stack1.pop();
	stack1.pop();
	std::cout << YE << "stack1 size : " << NC << stack1.size() << std::endl
		<< YE << "stack1 top : " << NC << stack1.top() << std::endl << std::endl;



	/******* testing member functions on a const stack *******/
	std::cout << GN << "Creation of stack4 (const) via copy constructor" << NC << std::endl;
	std::vector<int> const v2(v1);
	NAMESPACE::stack<int, std::vector<int> > const stack4(v2);
	std::cout << YE << "stack4 (const) empty : " << NC << (stack4.empty() ? "true" : "false") << std::endl
		<< YE << "stack4 (const) size : " << NC << stack4.size() << std::endl
		<< YE << "stack4 (const) top : " << NC << stack4.top() << std::endl
		<< YE << "stack4 (const) push \"11\"" << NC << "-> doesn't work "<< std::endl;
	//stack4.push(11); -> doesn't compile



	/***** testing non member functions *****
	*
	*	operators ==, !=, <, <=, >, >=
	*
	****** **************************** *****/
	std::cout << std::endl
		<< OR << "stack1 == stack2 : " << NC << (stack1 == stack2 ? "true" : "false") << std::endl
		<< OR << "stack1 != stack3 : " << NC << (stack1 != stack3 ? "true" : "false") << std::endl
		<< OR << "stack1 < stack2 : " << NC << (stack1 < stack2 ? "true" : "false") << std::endl
		<< OR << "stack2 <= stack3 : " << NC << (stack2 <= stack3 ? "true" : "false") << std::endl
		<< OR << "stack2 > stack3 : " << NC << (stack2 > stack3 ? "true" : "false") << std::endl
		<< OR << "stack2 >= stack3 : " << NC << (stack2 >= stack3 ? "true" : "false") << std::endl;

	std::cout << std::endl;

	return ;
}