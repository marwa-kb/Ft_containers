#ifndef TESTS_H
# define TESTS_H

/*** STL ***/
#include <stack>
#include <vector>
#include <map>

#include <iostream>
#include <string>
#include <algorithm>

/*** MINE ***/
#include "../srcs/stack.hpp"
#include "../srcs/vector.hpp"
#include "../srcs/map.hpp"

#include "../srcs/iterator.hpp"
#include "../srcs/colors.h"


void stack_tests();


void vector_tests();
template <typename T>
void print(NAMESPACE::vector<T> x, std::string s = "vector");


void map_tests();

#endif