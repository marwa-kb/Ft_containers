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
	first['w'] = 30000;
	first['x'] = 30000;
	first['y'] = 30000;
	first['z'] = 30000;
	print_map(first, "first");

	NAMESPACE::map<char,int> first_dup;
	first_dup = first;
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


	/*insert*/
/*	{
		std::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
				std::cout << "element 'z' already existed";
				std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));		// max efficiency inserting
		mymap.insert (it, std::pair<char,int>('c',400));		// no max efficiency inserting

		// third insert function version (range insertion):
		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
	}*/

	/*count*/
	/*
	{
		std::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
  		}
	}
*/


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
