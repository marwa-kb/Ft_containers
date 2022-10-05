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

	/*find*/
	{
		std::cout << GN << "\n*find*" << NC << std::endl;

		NAMESPACE::map<int, std::string> m;
		NAMESPACE::map<int, std::string>::iterator it;
		NAMESPACE::map<int, std::string>::iterator end;
		m[1] = "hello";
		m[2] = "how";
		m[3] = "are";
		m[4] = "you";
		m[5] = "?";
		m[6] = "I'm";
		m[7] = "fine";
		m[8] = "thank";
		m[9] = "you!";
		m[10] = "hello";
		m[20] = "how";
		m[30] = "are";
		m[40] = "you";
		m[50] = "?";
		m[60] = "I'm";
		m[70] = "fine";
		m[80] = "thank";
		m[90] = "you!";
		m[11] = "hello";
		m[21] = "how";
		m[31] = "are";
		m[41] = "you";
		m[51] = "?";
		m[61] = "I'm";
		m[71] = "fine";
		m[81] = "thank";
		m[91] = "you!";
		m[12] = "hello";
		m[22] = "how";
		m[32] = "are";
		m[42] = "you";
		m[52] = "?";
		m[62] = "I'm";
		m[72] = "fine";
		m[82] = "thank";
		m[92] = "you!";
		m[13] = "hello";
		m[23] = "how";
		m[33] = "are";
		m[43] = "you";
		m[53] = "?";
		m[63] = "I'm";
		m[73] = "fine";
		m[83] = "thank";
		m[93] = "you!";
		m[14] = "hello";
		m[24] = "how";
		m[34] = "are";
		m[44] = "you";
		m[54] = "?";
		m[64] = "I'm";
		m[74] = "fine";
		m[84] = "thank";
		m[94] = "you!";
		m[15] = "hello";
		m[25] = "how";
		m[35] = "are";
		m[45] = "you";
		m[55] = "?";
		m[65] = "I'm";
		m[75] = "fine";
		m[85] = "thank";
		m[95] = "you!";
		m[16] = "hello";
		m[26] = "how";
		m[36] = "are";
		m[46] = "you";
		m[56] = "?";
		m[66] = "I'm";
		m[76] = "fine";
		m[86] = "thank";
		m[96] = "you!";
		m[17] = "hello";
		m[27] = "how";
		m[37] = "are";
		m[47] = "you";
		m[57] = "?";
		m[67] = "I'm";
		m[77] = "fine";
		m[87] = "thank";
		m[97] = "you!";
		m[18] = "hello";
		m[28] = "how";
		m[38] = "are";
		m[48] = "you";
		m[58] = "?";
		m[68] = "I'm";
		m[78] = "fine";
		m[88] = "thank";
		m[98] = "you!";
		m[19] = "hello";
		m[29] = "how";
		m[39] = "are";
		m[49] = "you";
		m[59] = "?";
		m[69] = "I'm";
		m[79] = "fine";
		m[89] = "thank";
		m[99] = "you!";
		m[100] = "hello";
		m[200] = "how";
		m[300] = "are";
		m[400] = "are";
		m[500] = "?";
		m[600] = "I'm";
		m[700] = "fine";
		m[800] = "thank";
		m[900] = "you!";
		m[112] = "hello";
		m[212] = "how";
		m[312] = "are";
		m[412] = "you";
		m[512] = "?";
		m[612] = "I'm";
		m[712] = "fine";
		m[812] = "thank";
		m[912] = "you!";
		m[1120] = "hello";
		m[2120] = "how";
		m[3120] = "are";
		m[4120] = "you";
		m[5120] = "?";
		m[6120] = "I'm";
		m[7120] = "fine";
		m[8120] = "thank";
		m[9120] = "you!";
		m[1121] = "hello";
		m[2121] = "how";
		m[3121] = "are";
		m[4121] = "you";
		m[5121] = "?";
		m[6121] = "I'm";
		m[7121] = "fine";
		m[8121] = "thank";
		m[9121] = "you!";
		m[1122] = "hello";
		m[2122] = "how";
		m[3122] = "are";
		m[4122] = "you";
		m[5122] = "?";
		m[6122] = "I'm";
		m[7122] = "fine";
		m[8122] = "thank";
		m[9122] = "you!";
		m[1123] = "hello";
		m[2123] = "how";
		m[3123] = "are";
		m[4123] = "you";
		m[5123] = "?";
		m[6123] = "I'm";
		m[7123] = "fine";
		m[8123] = "thank";
		m[9123] = "you!";
		m[1124] = "hello";
		m[2124] = "how";
		m[3124] = "are";
		m[4124] = "you";
		m[5124] = "?";
		m[6124] = "I'm";
		m[7124] = "fine";
		m[8124] = "thank";
		m[9124] = "you!";
		m[1125] = "hello";
		m[2125] = "how";
		m[3125] = "are";
		m[4125] = "you";
		m[5125] = "?";
		m[6125] = "I'm";
		m[7125] = "fine";
		m[8125] = "thank";
		m[9125] = "you!";
		m[1126] = "hello";
		m[2126] = "how";
		m[3126] = "are";
		m[4126] = "you";
		m[5126] = "?";
		m[6126] = "I'm";
		m[7126] = "fine";
		m[8126] = "thank";
		m[9126] = "you!";
		m[1127] = "hello";
		m[2127] = "how";
		m[3127] = "are";
		m[4127] = "you";
		m[5127] = "?";
		m[6127] = "I'm";
		m[7127] = "fine";
		m[8127] = "thank";
		m[9127] = "you!";
		m[1128] = "hello";
		m[2128] = "how";
		m[3128] = "are";
		m[4128] = "you";
		m[5128] = "?";
		m[6128] = "I'm";
		m[7128] = "fine";
		m[8128] = "thank";
		m[9128] = "you!";
		m[1129] = "hello";
		m[2129] = "how";
		m[3129] = "are";
		m[4129] = "you";
		m[5129] = "?";
		m[6129] = "I'm";
		m[7129] = "fine";
		m[8129] = "thank";
		m[9129] = "you!";
		m[11200] = "hello";
		m[21200] = "how";
		m[31200] = "are";
		m[41200] = "are";
		m[51200] = "?";
		m[61200] = "I'm";
		m[71200] = "fine";
		m[81200] = "thank";
		m[91200] = "you!";
		print_map(m, "m");

		end = m.end();
		for (int x = 1; x < 900; x++)
		{
			it = m.find(x);
			std::cout << YE << "(find(" << x << ") : " << NC << (it == end ? "not found" : it->second) << std::endl;
		}
		
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
