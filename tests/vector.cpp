#include "tests.h"

void vector_tests()
{
	std::cout << BW << "                       ________" << NC << std::endl;
	std::cout << BW << "――――――――――――――――――――――| VECTOR |――――――――――――――――――――――" << NC << std::endl;
	std::cout << BW << "                       ‾‾‾‾‾‾‾‾" << NC << std::endl;


	/********* testing constructors *********/
	{
		std::cout << UG << "Testing constructors" << NC << std::endl;
		NAMESPACE::vector<std::string> words1;
		words1.push_back("the");
		words1.push_back("frogurt");
		words1.push_back("is");
		words1.push_back("also");
		words1.push_back("cursed");
		print_vector(words1, "words1");
	
		// words2 == words1
		NAMESPACE::vector<std::string> words2(words1.begin(), words1.end());
		print_vector(words2, "words2");
	
		// words3 == words1
		NAMESPACE::vector<std::string> words3(words1);
		print_vector(words3, "words3");
	
		// words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
		NAMESPACE::vector<std::string> words4(500, "Mo");
		print_vector(words4, "words4");
	}


	/******* testing member functions *******
	* 
	*		operators =, []
	*	assign, at, front, back, empty,
	*	size, reserve, capacity, clear,
	*	insert, erase, push_back, pop_back,
	*		resize, swap
	* 
	******* ************************** *******/

	std::cout << UG << "\nTesting member functions" << NC << std::endl;

	NAMESPACE::vector<int> v1(3, 41);

	print_vector(v1, "v1");
	std::cout << "v1 empty ? -> " << (v1.empty() ? "yes" : "no") << std::endl;
	v1.push_back(4);
	std::cout << YE << "push_back(4);\n" << NC << "size = " << v1.size() << std::endl;
	v1.push_back(3);
	std::cout << YE << "push_back(3);\n" << NC << "size = " << v1.size() << std::endl;
	v1.push_back(2);
	std::cout << YE << "push_back(2);\n" << NC << "size = " << v1.size() << std::endl;
	print_vector(v1, "v1");
	v1.pop_back();
	v1.pop_back();
	std::cout << YE << "pop_back() x 2;\n" << NC << "size = " << v1.size() << std::endl;
	std::cout << "capacity = " << v1.capacity() << std::endl;
	print_vector(v1, "v1");
	std::cout << std::endl;

	NAMESPACE::vector<int> v2;
	std::cout << "v2 empty ? -> " << (v2.empty() ? "yes" : "no") << std::endl;
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.reserve(3);
	std::cout << YE << "reserve(3);\n" << NC << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.push_back(74);
	v2.push_back(74);
	v2.push_back(74);
	v2.push_back(89);
	print_vector(v2, "v2");
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.assign(5, 10);
	std::cout << YE << "assign(5, 10)" << NC << std::endl;
	print_vector(v2, "v2");
	std::cout << YE << "clear() then push_back(89);" << NC << std::endl;
	v2.clear();
	v2.push_back(89);
	print_vector(v2, "v2");
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.resize(40, 12);
	std::cout << YE << "resize(40, 12);" << NC << std::endl;
	print_vector(v2, "v2");
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;


	/*assign*/
	{
		std::cout << GN << "\n*assign*" << NC << std::endl;
		NAMESPACE::vector<int> first;
		NAMESPACE::vector<int> second;
		NAMESPACE::vector<int> third;

		print_vector(first, "first");
		std::cout << YE << "assign(7, 100);" << NC << std::endl;
		first.assign (7,100);             // 7 ints with a value of 100
		print_vector(first, "first");
		std::cout << "size = " << first.size() << std::endl;
		std::cout << "capacity = " << first.capacity() << std::endl << std::endl;

		NAMESPACE::vector<int>::iterator it;
		it=first.begin()+1;

		print_vector(second, "second");
		std::cout << YE << "assign(it, first.end()-1);" << NC << std::endl;
		second.assign (it, first.end()-1); // the 5 central values of first
		print_vector(second, "second");
		std::cout << "size = " << second.size() << std::endl;
		std::cout << "capacity = " << second.capacity() << std::endl << std::endl;

		int myints[] = {1776,7,4};
		std::cout << "myints[] = {1776, 7, 4};" << std::endl;
		print_vector(third, "third");
		std::cout << YE << "assign(myints, myints + 3);" << NC << std::endl;
		third.assign (myints, myints + 3);   // assigning from array.
		print_vector(third, "third");
		std::cout << "size = " << third.size() << std::endl;
		std::cout << "capacity = " << third.capacity() << std::endl << std::endl;
	}


	/*insert*/
	{
		std::cout << GN << "\n*insert*" << NC << std::endl;
		NAMESPACE::vector<int> myvector (3,100);
		NAMESPACE::vector<int>::iterator it;

		print_vector(myvector, "myvector");
		it = myvector.begin();
		std::cout << YE << "insert(it, 200);" << NC << std::endl;
		it = myvector.insert(it, 200);
		print_vector(myvector, "myvector");

		std::cout << YE << "insert(it, 2, 300);" << NC << std::endl;
		myvector.insert(it,2,300);
		print_vector(myvector, "myvector");

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		NAMESPACE::vector<int> anothervector (2,400);

		print_vector(anothervector, "anothervector");
		std::cout << YE << "insert(it+2,anothervector.begin(),anothervector.end());" << NC << std::endl;
		myvector.insert(it+2,anothervector.begin(),anothervector.end());
		print_vector(myvector, "myvector");

		int myarray [] = { 501,502,503 };
		std::cout << "myarray[] = {501, 502, 503};" << std::endl;
		std::cout << YE << "insert(myvector.begin(), myarray, myarray+3);" << NC << std::endl;
		myvector.insert(myvector.begin(), myarray, myarray+3);
		print_vector(myvector, "myvector");
	}

	/*erase*/
	{
		std::cout << GN << "\n*erase*" << NC << std::endl;
		NAMESPACE::vector<int> c;
		c.push_back(0);
		c.push_back(1);
		c.push_back(2);
		c.push_back(3);
		c.push_back(4);
		c.push_back(5);
		c.push_back(6);
		c.push_back(7);
		c.push_back(8);
		c.push_back(9);
		c.push_back(10);
		print_vector(c, "c");
		
		std::cout << YE << "erase(c.begin());" << NC << std::endl;
		c.erase(c.begin());
		print_vector(c, "c");
		
		std::cout << YE << "erase(c.begin() + 2, c.begin() + 5);" << NC << std::endl;
		c.erase(c.begin() + 2, c.begin() + 5);
		print_vector(c, "c");
		
		// Erase all even numbers
		std::cout << YE << "erase even numbers" << NC << std::endl;
		for (NAMESPACE::vector<int>::iterator it = c.begin(); it != c.end(); ) {
			if (*it % 2 == 0)
				it = c.erase(it);
			else
				++it;
		}
		print_vector(c, "c");
	}

	/*swap*/
	{
		std::cout << GN << "\n*swap*" << NC << std::endl;
		NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
		NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200
		
		NAMESPACE::vector<int>::iterator foo1 = foo.begin();
		NAMESPACE::vector<int>::iterator bar1 = bar.begin();
		std::cout << UP << "Before swap" << NC << std::endl;
		print_vector(foo, "foo");
		std::cout << "size = " << foo.size() << std::endl;
		std::cout << "capacity = " << foo.capacity() << std::endl;
		std::cout << "foo.begin() = " << *foo1 << std::endl;
		print_vector(bar, "bar");
		std::cout << "size = " << bar.size() << std::endl;
		std::cout << "capacity = " << bar.capacity() << std::endl;
		std::cout << "bar.begin() = " << *bar1 << std::endl;

		foo.swap(bar);
		
		std::cout << UP << "\nAfter swap" << NC << std::endl;
		print_vector(foo, "foo");
		std::cout << "size = " << foo.size() << std::endl;
		std::cout << "capacity = " << foo.capacity() << std::endl;
		std::cout << "foo.begin() = " << *foo1 << std::endl;

		print_vector(bar, "bar");
		std::cout << "size = " << bar.size() << std::endl;
		std::cout << "capacity = " << bar.capacity() << std::endl;
		std::cout << "bar.begin() = " << *bar1 << std::endl;

		std::cout << UP << "\nOther swap fct" << NC << std::endl;
		swap(foo, bar);
		print_vector(foo, "foo");
		print_vector(bar, "bar");
	}


	/*************** iterators **************
	* 
	*		begin, end, rbegin, rend
	*			+ const versions	
	* 
	******** *********************** *******/
	{
		std::cout << UG << "\nTesting iterators" << NC << std::endl;

		NAMESPACE::vector<int> test;
		test.push_back(1);
		test.push_back(22);
		test.push_back(333);

		NAMESPACE::vector<int>::iterator beg = test.begin();
		NAMESPACE::vector<int>::iterator beg1 = test.begin();
		NAMESPACE::vector<int>::iterator end = test.end();

		std::cout << RE << "beginning = " << *beg << NC << std::endl;
		for (; beg != end; beg++)
			std::cout << BY << *beg << " " << NC;
		std::cout << std::endl;

		std::cout << UO << "TEST ALGORITHM 1" << NC << std::endl;
		if (std::find(beg1, end, 333) == end)
			std::cout << BO << "value not found" << NC << std::endl;
		else
			std::cout << BG << "value found" << NC << std::endl;
		std::cout << BY << (std::find(beg1, end, 333) == end ? "OUI end" : "NOT END") << NC << std::endl;


		NAMESPACE::vector<int>::reverse_iterator rbeg = test.rbegin();
		NAMESPACE::vector<int>::reverse_iterator rbeg1 = test.rbegin();
		NAMESPACE::vector<int>::reverse_iterator rend = test.rend();
		std::cout << RE << "rbeginning = " << *rbeg << NC << std::endl;
		for (; rbeg != rend; rbeg++)
			std::cout << BY << *rbeg << " " << NC;
		std::cout << std::endl << GN << "------------" << NC << std::endl;

		std::cout << UO << "TEST ALGORITHM 2" << NC << std::endl;
		if (std::find(rbeg1, rend, 333) == rend)
			std::cout << BO << "value not found" << NC << std::endl;
		else
			std::cout << BG << "value found" << NC << std::endl;
				

		NAMESPACE::vector<int>::iterator iter;
		NAMESPACE::vector<int>::const_iterator const_iter;
		const_iter = iter;
		// iter = const_iter; --> should not work
		for (NAMESPACE::vector<int>::iterator a = test.begin(); a != test.end(); a++)
			std::cout << BY << *a << " " << NC;
		std::cout << std::endl;

		std::cout << "size = " << test.size() << std::endl;
		std::cout << "capacity = " << test.capacity() << std::endl;
		test.insert(test.begin() + 2, 5, 88);
		std::cout << "size = " << test.size() << std::endl;
		std::cout << "capacity = " << test.capacity() << std::endl;
		test.insert(test.end(), 2, 5);
		for (NAMESPACE::vector<int>::iterator a = test.begin(); a != test.end(); a++)
			std::cout << BY << *a << " " << NC;
		std::cout << std::endl;
		std::cout << "size = " << test.size() << std::endl;
		std::cout << "capacity = " << test.capacity() << std::endl;

		NAMESPACE::vector<std::string>::reverse_iterator iter2;
		NAMESPACE::vector<std::string>::const_reverse_iterator const_iter2;
		const_iter2 = iter2;
		//iter = const_iter; -> should not work
	}

	/***** testing non member functions *****
	*
	*	operators ==, !=, <, <=, >, >=
	*
	****** **************************** *****/
	std::cout << UG << "\nTesting non member functions" << NC << std::endl;
	
	std::cout << (v1 == v2 ? "same" : "different") << std::endl;
	std::cout << (v1 != v1 ? "not same" : "not different") << std::endl;
	std::cout << (v1 < v2 ? "inferior" : "superior or equal") << std::endl;
	std::cout << (v1 > v1 ? "superior" : "inferior or equal") << std::endl;
	std::cout << (v1 <= v2 ? "inferior or equal" : "superior") << std::endl;
	std::cout << (v1 >= v1 ? "superior or equal" : "inferior") << std::endl;

}


template <typename T>
void print_vector(NAMESPACE::vector<T> & x, std::string s)
{
	std::cout << BW << s << ":" << NC;
	for (typename NAMESPACE::vector<T>::iterator a = x.begin(); a != x.end(); a++)
		std::cout << " | " << BC << *a << NC;
	std::cout << " | " << std::endl;
}
