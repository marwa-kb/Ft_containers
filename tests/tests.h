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
#include "colors.h"

#include "../srcs/vector.hpp"
#include "../srcs/stack.hpp"
#include "../srcs/map.hpp"

void stack_tests();

void vector_tests();
template <typename T>
void print_vector(NAMESPACE::vector<T> & x, std::string s = "vector");

void map_tests();
template <class Key, class T>
void print_map(NAMESPACE::map<Key, T> & x, std::string s = "map");

#endif