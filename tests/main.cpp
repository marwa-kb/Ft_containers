#include "tests.h"
// /!\ remets les tests quand t'as fini
int main(int argc, char *argv[])
{
	if (argc == 1 || (argv[1] && std::string(argv[1]) == "stack"))
		stack_tests();

	if (argc == 1 || (argv[1] && std::string(argv[1]) == "vector"))
		vector_tests();

	if (argc == 1 || (argv[1] && std::string(argv[1]) == "map"))
		map_tests();	



	/*******************IS INTEGRAL**********************/
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
/*
	int a[] {0, 1, 2, 3};
 
	std::reverse_iterator<int*> x = std::rend(a) - std::size(a);
	std::reverse_iterator<int*> y = std::rend(a) - std::size(a);
	std::reverse_iterator<int*> z = std::rbegin(a) + 1;
 
	std::cout
		<< std::boolalpha
		<< "*x == " << *x << '\n' // 3
		<< "*y == " << *y << '\n' // 3
		<< "*z == " << *z << '\n' // 2
		<< "x == y ? " << (x == y) << '\n' // true
		<< "x != y ? " << (x != y) << '\n' // false
		<< "x <  y ? " << (x <  y) << '\n' // false
		<< "x <= y ? " << (x <= y) << '\n' // true
		<< "x == z ? " << (x == z) << '\n' // false
		<< "x != z ? " << (x != z) << '\n' // true
		<< "x <  z ? " << (x <  z) << '\n' // true!
		<< "x <= z ? " << (x <= z) << '\n' // true
		;
*/
	return (0);
}