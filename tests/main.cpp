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
	return (0);
}