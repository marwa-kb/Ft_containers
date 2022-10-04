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
	
	// first_dup == first
	NAMESPACE::map<char,int> first_dup = first;
	print_map(first_dup, "first_dup");

	// second == first
	NAMESPACE::map<char,int> second(first.begin(),first.end());
	print_map(second, "second");

	// second == first
	NAMESPACE::map<char,int> third(second);
	print_map(third, "third");



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

		// second insert function version (with hint position): 
		NAMESPACE::map<char,int>::iterator it = mymap.begin();
		NAMESPACE::map<char,int>::iterator itret = mymap.insert(it, NAMESPACE::pair<char,int>('b', 300));		// max efficiency inserting
		if (itret == mymap.end())
			std::cout << BR << "NOPE" << NC << std::endl;
		else
			std::cout << UP << "itret: " << itret->first << ", " << itret->second << NC << std::endl;
		print_map(mymap, "mymap");
		NAMESPACE::map<char,int>::iterator itret1 = mymap.insert(it, NAMESPACE::pair<char,int>('c', 400));		// no max efficiency inserting
		if (itret1 == mymap.end())
			std::cout << BR << "NOPE" << NC << std::endl;
		else
			std::cout << UP << "itret1: " << itret1->first << ", " << itret1->second << NC << std::endl;

		// third insert function version (range insertion):
		NAMESPACE::map<char,int> anothermap;
		anothermap.insert(mymap.begin(), mymap.end());

		// showing contents:
		print_map(mymap, "mymap");
		print_map(anothermap, "anothermap");
	}

	/*erase*/
	{
		std::cout << GN << "\n*erase*" << NC << std::endl;

		NAMESPACE::map<char,int> mymap;
		NAMESPACE::map<char,int>::iterator it;
		NAMESPACE::map<char,int>::iterator it2;
		// insert some values:
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		mymap['d'] = 40;
		mymap['e'] = 50;
		mymap['f'] = 60;
		mymap['g'] = 70;
		mymap['h'] = 80;
		print_map(mymap, "mymap");

		it = mymap.find('e');
		mymap.erase(it);	// erasing by iterator
		std::cout << YE << "erase(find('e'));" << NC << std::endl;
		std::cout << "size = " << mymap.size() << std::endl;
		print_map(mymap, "mymap");

		mymap.erase('b');		// erasing by key
		std::cout << YE << "erase('b');" << NC << std::endl;
		std::cout << "size = " << mymap.size() << std::endl;
		print_map(mymap, "mymap");

		mymap.erase('d');		// erasing by key
		std::cout << YE << "erase('d');" << NC << std::endl;
		std::cout << "size = " << mymap.size() << std::endl;
		print_map(mymap, "mymap");

		it = mymap.find('c');
		mymap.erase(it, mymap.end());	// erasing by range
		std::cout << YE << "erase(find('c'), mymap.end());" << NC << std::endl;
		std::cout << "size = " << mymap.size() << std::endl;
		print_map(mymap, "mymap");
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

	/*value_comp*/
	{
		std::cout << GN << "\n*value_comp*" << NC << std::endl;
		
		NAMESPACE::map<char, int> mymap;
  		mymap['x'] = 1001;
		mymap['y'] = 2002;
		mymap['z'] = 3003;
		
		std::cout << "mymap contains:\n";
		
		NAMESPACE::pair<char, int> highest = *mymap.rbegin();
		
		NAMESPACE::map<char, int>::iterator it = mymap.begin();
		do
			std::cout << it->first << " => " << it->second << '\n';
		while (mymap.value_comp()(*it++, highest));
	}

	/*key_comp*/
	{
		std::cout << GN << "\n*key_comp*" << NC << std::endl;

		NAMESPACE::map<char, int> mymap;
		NAMESPACE::map<char, int>::key_compare mycomp = mymap.key_comp();
		mymap['a'] = 100;
		mymap['b'] = 200;
		mymap['c'] = 300;
		
		std::cout << "mymap contains:\n";
		char highest = mymap.rbegin()->first;     // key value of last element
		NAMESPACE::map<char, int>::iterator it = mymap.begin();
		do
			std::cout << it->first << " => " << it->second << '\n';
		while (mycomp((*it++).first, highest));
		std::cout << std::endl;
	}

	/*swap*/
	{
		std::cout << GN << "\n*swap*" << NC << std::endl;

		NAMESPACE::map<int, std::string> foo, bar;

		foo[10] = "dix";
		foo[20] = "vingt";

 		bar[30] = "trente";
		bar[40] = "quarante";
		bar[50] = "cinquante";

		print_map(foo, "foo");
		std::cout << YE << "foo.size() = " << foo.size() << NC << std::endl;
		print_map(bar, "bar");
		std::cout << YE << "bar.size() = " << bar.size() << NC << std::endl;
		foo.swap(bar);
		std::cout << YE << "foo.swap(bar);" << NC << std::endl;
		print_map(foo, "foo");
		std::cout << YE << "foo.size() = " << foo.size() << NC << std::endl;
		print_map(bar, "bar");
		std::cout << YE << "bar.size() = " << bar.size() << NC << std::endl;
	}

	/*lower_bound, upper_bound, equal_range*/
	{
		std::cout << GN << "\n*lower_bound, upper_bound, equal_range*" << NC << std::endl;

		NAMESPACE::map<int, float> mymap;
		NAMESPACE::map<int, float>::iterator itlow, itup;
		mymap[1] = 1.1f;
		mymap[2] = 2.2f;
		mymap[3] = 3.3f;
		mymap[4] = 4.4f;
		mymap[5] = 5.5f;
		print_map(mymap, "mymap");

		itlow = mymap.lower_bound(1);	// itlow points to 2
		if (itlow != mymap.end())
			std::cout << YE << "mymap.lower_bound(2) = " << NC << itlow->first << std::endl;
		else
			std::cout << "nope" << std::endl;

		itup = mymap.upper_bound(2);	 // itup points to 5 (not 4!)
		if (itup != mymap.end())
			std::cout << YE << "mymap.upper_bound(4) = " << NC << itup->first << std::endl;
		else
			std::cout << "nope" << std::endl;
		
		mymap.erase(itlow, itup);	// erases [itlow,itup)
		print_map(mymap, "mymap");

		// NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, NAMESPACE::map<int, float>::iterator> ret;
		// ret = mymap.equal_range(5);
		// std::cout << YE << "equal_range(5) from " NC << "(" << ret.first->first << ", " << ret.first->second << ")";
		// std::cout << YE << " to " NC << "(" << ret.second->first << ", " << ret.second->second << ")" << '\n';
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

	NAMESPACE::map<int, int>::iterator iter;
	NAMESPACE::map<int, int>::const_iterator const_iter;
	const_iter = iter;
	// iter = const_iter; // --> should not work

	NAMESPACE::map<int, int>::reverse_iterator r_iter;
	NAMESPACE::map<int, int>::const_reverse_iterator const_r_iter;
	const_r_iter = r_iter;
	// r_iter = const_r_iter; // --> should not work


	/***** testing non member functions *****
	*
	*	operators ==, !=, <, <=, >, >=
	*
	****** **************************** *****/

	std::cout << UG << "\nTesting non member functions" << NC << std::endl;

	NAMESPACE::map<char,int> foo, bar;
	foo['a'] = 100;
	foo['b'] = 200;
	bar['a'] = 10;
	bar['z'] = 1000;
	print_map(foo, "foo");
	print_map(bar, "bar");

	std::cout << "foo and bar are " << (foo == bar ? "equal" : "different") << std::endl;
	std::cout << "foo and foo are " << (foo != foo ? "different" : "equal") << std::endl;
	std::cout << "foo is " << (foo < bar ? "inferior" : "superior or equal") << " to bar" << std::endl;
	std::cout << "foo is " << (foo > foo ? "superior" : "inferior or equal") << " to foo" << std::endl;
	std::cout << "foo is " << (foo <= bar ? "inferior or equal" : "superior") << " to bar" << std::endl;
	std::cout << "foo is " << (foo >= foo ? "superior or equal" : "inferior") << " to foo" << std::endl;
	
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
