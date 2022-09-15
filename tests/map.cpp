#include "tests.h"
#include "../srcs/avl.hpp"

void map_tests()
{
	std::cout << BW << "                       _____" << NC << std::endl;
	std::cout << BW << "――――――――――――――――――――――| MAP |――――――――――――――――――――――" << NC << std::endl;
	std::cout << BW << "                       ‾‾‾‾‾" << NC << std::endl;

	std::cout << CY << "Test AVL" << NC << std::endl;

	ft::pair<std::string, int> p("hello", 1);
	avl<std::string, int> x(p);

	return ;
}