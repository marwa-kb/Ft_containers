#include "tests.h"

void map_tests()
{
	std::cout << BW << "                       _____" << NC << std::endl;
	std::cout << BW << "――――――――――――――――――――――| MAP |――――――――――――――――――――――" << NC << std::endl;
	std::cout << BW << "                       ‾‾‾‾‾" << NC << std::endl;


	/********* testing constructors *********/
	std::cout << UG << "Testing constructors" << NC << std::endl;

	NAMESPACE::map<char,int> first;
	print_map(first, "first");
	std::cout << "first empty ? " << (first.empty() ? "yes" : "no") << std::endl;
	std::cout << "first size = " << first.size() << std::endl;
	first.insert(NAMESPACE::pair<char, int>('a', 100));
	first.insert(NAMESPACE::pair<char, int>('b', 200));
	first.insert(NAMESPACE::pair<char, int>('c', 300));
	first.insert(NAMESPACE::pair<char, int>('d', 400));
	first.insert(NAMESPACE::pair<char, int>('e', 500));
	first.insert(NAMESPACE::pair<char, int>('f', 600));
	print_map(first, "first");
	std::cout << "first empty ? " << (first.empty() ? "yes" : "no") << std::endl;
	std::cout << "first size = " << first.size() << std::endl;
	first.erase('a');
	std::cout << YE << "erase('a');" << NC << std::endl;
	print_map(first, "first");
	std::cout << "first empty ? " << (first.empty() ? "yes" : "no") << std::endl;
	std::cout << "first size = " << first.size() << std::endl;
	first.erase('x');
	std::cout << YE << "erase('x');" << NC << std::endl;
	print_map(first, "first");
	std::cout << "first empty ? " << (first.empty() ? "yes" : "no") << std::endl;
	std::cout << "first size = " << first.size() << std::endl;
	std::cout << YE << "count('f') = " << NC << first.count('f') << std::endl;
	std::cout << YE << "count('x') = " << NC << first.count('x') << std::endl;
	std::cout << YE << "find('b') : " << NC << (first.find('b') == first.end() ? "not found" : "found") << std::endl;
	std::cout << YE << "find('a') : " << NC << (first.find('a') == first.end() ? "not found" : "found") << std::endl;
	first.clear();
	std::cout << YE << "clear();" << NC << std::endl;
	print_map(first, "first");
	std::cout << "first empty ? " << (first.empty() ? "yes" : "no") << std::endl;
	std::cout << "first size = " << first.size() << std::endl;
	std::cout << YE << "first['w'] = 100;" << NC << std::endl;
	std::cout << YE << "first['x'] = 300;" << NC << std::endl;
	std::cout << YE << "first['y'] = 500;" << NC << std::endl;
	std::cout << YE << "first['z'] = 700;" << NC << std::endl;
	first['w'] = 100;
	first['x'] = 300;
	first['y'] = 500;
	first['z'] = 700;
	print_map(first, "first");

	NAMESPACE::map<char,int> first_dup(first);
	print_map(first, "first");
	print_map(first_dup, "first_dup");

	
	

	// NAMESPACE::map<char,int> second(first.begin(),first.end());

	// NAMESPACE::map<char,int> third(second);

	// NAMESPACE::map<char,int,classcomp> fourth;								 // class as Compare

	// bool(*fn_pt)(char,char) = fncomp;
	// NAMESPACE::map<char, int, bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare




	/******* testing member functions *******
	* 
	*		operators =, []
	*	assign, at, empty, size, insert,
	*	erase, clear, key_comp, value_comp,
	*	find, count, lower_bound, upper_bound,
	*			equal_range, swap
	* 
	******* ************************** *******/

	std::cout << UG << "\nTesting member functions" << NC << std::endl;

	/*at*/
	{
		std::cout << GN << "\n*at*" << NC << std::endl;

		NAMESPACE::map<std::string,int> mymap;
		mymap.insert(NAMESPACE::make_pair("alpha", 0));
		mymap.insert(NAMESPACE::make_pair("beta", 0));
		mymap.insert(NAMESPACE::make_pair("gamma", 0));

 		mymap.at("alpha") = 10;
		mymap.at("beta") = 20;
		mymap.at("gamma") = 30;
		print_map(mymap, "mymap");
		//std::cout << "lambda exists? " << mymap.at("lambda") << std::endl;	//-->throws std::out_of_range
		std::cout << "lambda exists? " << mymap["lambda"] << std::endl;  		//-->works
	}

	/*insert*/
	{
		std::cout << GN << "\n*insert*" << NC << std::endl;

		NAMESPACE::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert(NAMESPACE::pair<char,int>('a', 100));
		mymap.insert(NAMESPACE::pair<char,int>('z', 600));
		print_map(mymap, "mymap");

		NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret;
		ret = mymap.insert(NAMESPACE::pair<char,int>('z', 500));
		if (!ret.second)
			std::cout << "element 'z' already existed with a value of " << ret.first->second << std::endl;
		else
			std::cout << "element 'z' succcesfully inserted" << std::endl;
		print_map(mymap, "mymap");

	// /!\ pb
		// second insert function version (with hint position): 
		// NAMESPACE::map<char,int>::iterator it = mymap.begin();
		// NAMESPACE::map<char,int>::iterator itret = mymap.insert(it, NAMESPACE::pair<char,int>('b', 300));		// max efficiency inserting
		// if (itret == mymap.end())
		// 	std::cout << BR << "NOPE" << NC << std::endl;
		// else
		// 	std::cout << UP << "itret: " << itret->first << ", " << itret->second << NC << std::endl;
		// print_map(mymap, "mymap");
		// NAMESPACE::map<char,int>::iterator itret1 = mymap.insert(it, NAMESPACE::pair<char,int>('c', 400));		// no max efficiency inserting
		// if (itret1 == mymap.end())
		// 	std::cout << BR << "NOPE" << NC << std::endl;
		// else
		// 	std::cout << UP << "itret1: " << itret1->first << ", " << itret1->second << NC << std::endl;

		// third insert function version (range insertion):
		NAMESPACE::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.end());

		// showing contents:
		print_map(mymap, "mymap");
		print_map(anothermap, "anothermap");
	}

	/*erase*/
	{
		std::cout << GN << "\n*erase*" << NC << std::endl;

		NAMESPACE::map<char,int> mymap;
		NAMESPACE::map<char,int>::iterator it;
		// insert some values:
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		mymap['d'] = 40;
		mymap['e'] = 50;
		mymap['f'] = 60;
		print_map(mymap, "mymap");

		// it = mymap.find('b');
		// mymap.erase(it);	// erasing by iterator
		// std::cout << YE << "erase(find('b'));" << NC << std::endl;
		// print_map(mymap, "mymap");
		// mymap.erase('c');		// erasing by key
		// std::cout << YE << "erase('c');" << NC << std::endl;
		// print_map(mymap, "mymap");
		// it = mymap.find('e');
		// mymap.erase(it, mymap.end());	// erasing by range
		// std::cout << YE << "erase(find('e'), mymap.end());" << NC << std::endl;
		// print_map(mymap, "mymap");

	}

	/*count*/
	{
		std::cout << GN << "\n*count*" << NC << std::endl;

		NAMESPACE::map<char,int> mymap;
		char c;
		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;
		print_map(mymap, "mymap");
		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c))
				std::cout << MA << " is an element of mymap" << NC << std::endl;
			else 
				std::cout << RE << " is not an element of mymap" << NC << std::endl;
		}
	}


	/*************** iterators **************
	* 
	*		begin, end, rbegin, rend
	*			+ const versions	
	* 
	******** *********************** *******/
	
	std::cout << UG << "\nTesting iterators" << NC << std::endl;
	
	NAMESPACE::map<char, int>::iterator a = first.begin();
	NAMESPACE::map<char, int>::iterator b = first.end();
	for (; a != b; a++)
		std::cout << " [ " << YE << a->first << NC << " ] = " << BC << a->second << NC << " |";
	std::cout << std::endl;
	NAMESPACE::map<char, int>::reverse_iterator c = first.rbegin();
	NAMESPACE::map<char, int>::reverse_iterator d = first.rend();
	for (; c != d; c++)
		std::cout << " [ " << YE << c->first << NC << " ] = " << BC << c->second << NC << " |";
	std::cout << std::endl;
	
	return ;
}


template <class Key, class T>
void print_map(NAMESPACE::map<Key, T> & x, std::string s)
{
	std::cout << BW << s << ":" << NC;
	for (typename NAMESPACE::map<Key, T>::iterator a = x.begin(); a != x.end(); a++)
		std::cout << " [ " << YE << a->first << NC << " ] = " << BC << a->second << NC << " |";
	std::cout << std::endl;
}
