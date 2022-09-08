#include "tests.h"

void vector_tests()
{
	std::cout << BW << " ________" << NC << std::endl;
	std::cout << BW << "| VECTOR |" << NC << std::endl;
	std::cout << BW << " ‾‾‾‾‾‾‾‾" << NC << std::endl;
			
	NAMESPACE::vector<int> v2;
	std::cout << GN << "size = " << v2.size() << NC << std::endl;
	std::cout << GN << "capacity = " << v2.capacity() << NC << std::endl;
	v2.reserve(3);
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.push_back(74);
	v2.push_back(74);
	v2.push_back(74);
	v2.push_back(89);
	int size = v2.size();
	for (int i = 0; i < size; i++)
		std::cout << YE << v2[i] << NC << std::endl;
	std::cout << MA << "size = " << v2.size() << NC << std::endl;
	std::cout << MA << "capacity = " << v2.capacity() << NC << std::endl;
	v2.assign(5, 10);
	v2.push_back(89);
	size = v2.size();
	for (int j = 0; j < size; j++)
		std::cout << YE << v2.at(j) << NC << std::endl;
	std::cout << MA << "size = " << v2.size() << NC << std::endl;
	std::cout << MA << "capacity = " << v2.capacity() << NC << std::endl;
	v2.push_back(89);
	v2.resize(101, 12);
	size = v2.size();
	std::cout << RE << "size = " << v2.size() << NC << std::endl;
	std::cout << RE << "capacity = " << v2.capacity() << NC << std::endl;
			

	NAMESPACE::vector<int> v1(3, 41);
	std::cout << "size = " << v1.size() << std::endl;
	v1.push_back(4);
	std::cout << "size = " << v1.size() << std::endl;
	v1.push_back(3);
	std::cout << "size = " << v1.size() << std::endl;
	v1.push_back(2);
	std::cout << "size = " << v1.size() << std::endl;
	int size1 = v1.size();
	std::cout << "size = " << size1 << std::endl;
	for (int i = 0; i < size1; i++)
		std::cout << "value = " << v1[i] << std::endl;
	v1.pop_back();
	v1.pop_back();
	std::cout << "capacity = " << v1.capacity() << std::endl;
	size1 = v1.size();
	std::cout << "size = " << size1 << std::endl;
	for (int i = 0; i < size1; i++)
		std::cout << "value = " << v1[i] << std::endl;

	std::cout << (v1 == v2 ? "same" : "different") << std::endl;
	std::cout << (v1 != v1 ? "not same" : "not different") << std::endl;
	std::cout << (v1 < v2 ? "less" : "more") << std::endl;
	std::cout << (v1 > v1 ? "more" : "less") << std::endl;

	std::cout << BC << "------------" << NC << std::endl;

	NAMESPACE::vector<int> test;
	test.push_back(1);
	test.push_back(22);
	test.push_back(333);
			

	NAMESPACE::vector<int>::iterator beg = test.begin();
	NAMESPACE::vector<int>::iterator beg1 = test.begin();
	NAMESPACE::vector<int>::iterator end = test.end();

	std::cout << BG << "beginning = " << *beg << NC << std::endl;
	for (; beg != end; beg++)
		std::cout << BY << *beg << " " << NC;
	std::cout << std::endl;

	std::cout << UO << "TEST ALGORTIHM 1" << NC << std::endl;
	if (std::find(beg1, end, 333) == end)
		std::cout << BO << "value not found" << NC << std::endl;
	else
		std::cout << BG << "value found" << NC << std::endl;
	std::cout << BY << (std::find(beg1, end, 333) == end ? "OUI end" : "NOT END") << NC << std::endl;
	// std::cout << UC << *(std::find(beg1, end, 333)) << NC << std::endl;


	NAMESPACE::vector<int>::reverse_iterator rbeg = test.rbegin();
	NAMESPACE::vector<int>::reverse_iterator rbeg1 = test.rbegin();
	NAMESPACE::vector<int>::reverse_iterator rend = test.rend();
	std::cout << BG << "rbeginning = " << *rbeg << NC << std::endl;
	// std::cout << BG << "rend = " << *rend << NC << std::endl;
	for (; rbeg != rend; rbeg++)
		std::cout << BY << *rbeg << " " << NC;
	std::cout << std::endl << BC << "------------" << NC << std::endl;

	std::cout << UO << "TEST ALGORTIHM 2" << NC << std::endl;
	if (std::find(rbeg1, rend, 333) == rend)
		std::cout << BO << "value not found" << NC << std::endl;
	else
		std::cout << BG << "value found" << NC << std::endl;
			
	std::cout << BY << (std::find(rbeg1, rend, 333) == rend ? "OUI end" : "NOT END") << NC << std::endl;

	NAMESPACE::vector<int>::iterator iter;
	NAMESPACE::vector<int>::const_iterator const_iter;
	const_iter = iter;
	// iter = const_iter;
	for (NAMESPACE::vector<int>::iterator a = test.begin(); a != test.end(); a++)
		std::cout << BY << *a << " " << NC;
	std::cout << std::endl;

	std::cout << GN << "size = " << test.size() << NC << std::endl;
	std::cout << GN << "capacity = " << test.capacity() << NC << std::endl;
	test.insert(test.begin() + 2, 5, 88);
	std::cout << GN << "size = " << test.size() << NC << std::endl;
	std::cout << GN << "capacity = " << test.capacity() << NC << std::endl;
	test.insert(test.end(), 2, 5);
	for (NAMESPACE::vector<int>::iterator a = test.begin(); a != test.end(); a++)
		std::cout << BY << *a << " " << NC;
	std::cout << std::endl;
	std::cout << GN << "size = " << test.size() << NC << std::endl;
	std::cout << GN << "capacity = " << test.capacity() << NC << std::endl;

	print(test);
	std::cout << YE << "erase 2nd element : " << NC << std::endl;
	test.erase(test.begin() + 1);
	print(test);
	std::cout << YE << "erase 1st element : " << NC << std::endl;
	test.erase(test.begin());
	print(test);
	std::cout << YE << "erase last element : " << NC << std::endl;
	test.erase(test.end() - 1);
	print(test);
	std::cout << YE << "erase from 2nd to before last element : " << NC << std::endl;
	test.erase(test.end() - 1, test.end() - 1);
	print(test);
	// NAMESPACE::vector<std::string>::reverse_iterator iter2(iter);
	// std::vector<std::string>::reverse_iterator iter3(iter);
	// ft::vector<std::string>::reverse_iterator iter4(iter);
	// NAMESPACE::vector<std::string>::const_reverse_iterator const_iter2;
	// const_iter2 = iter2;
	// iter = const_iter;



	/*****************ASSIGN******************/
	NAMESPACE::vector<int> first;
  	NAMESPACE::vector<int> second;
  	NAMESPACE::vector<int> third;

	print(first);
  	first.assign (7,100);             // 7 ints with a value of 100
	print(first);
	std::cout << GN << "size = " << first.size() << NC << std::endl;
	std::cout << GN << "capacity = " << first.capacity() << NC << std::endl;

  	NAMESPACE::vector<int>::iterator it;
  	it=first.begin()+1;

	print(second);
  	second.assign (it,first.end()-1); // the 5 central values of first
	print(second);
	std::cout << GN << "size = " << second.size() << NC << std::endl;
	std::cout << GN << "capacity = " << second.capacity() << NC << std::endl;

  	int myints[] = {1776,7,4};
	print(third);
  	third.assign (myints,myints+3);   // assigning from array.
	print(third);
	std::cout << GN << "size = " << third.size() << NC << std::endl;
	std::cout << GN << "capacity = " << third.capacity() << NC << std::endl;

  	std::cout << "Size of first: " << int (first.size()) << '\n';
  	std::cout << "Size of second: " << int (second.size()) << '\n';
  	std::cout << "Size of third: " << int (third.size()) << '\n';



	/************** INSERT ******************/
	{
		NAMESPACE::vector<int> myvector (3,100);
		NAMESPACE::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );
		print(myvector);

		myvector.insert (it,2,300);
		print(myvector);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		NAMESPACE::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		print(myvector);

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);
		print(myvector);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	/************ERASE *************/
	{
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
		print(c);
		
		c.erase(c.begin());
		print(c);
		
		c.erase(c.begin()+2, c.begin()+5);
		print(c);
		
		// Erase all even numbers
		for (NAMESPACE::vector<int>::iterator it = c.begin(); it != c.end(); ) {
			std::cout << BO << "*it % 2 <=> " << *it << " % 2 = " << *it % 2 << NC << std::endl;
			if (*it % 2 == 0)
				it = c.erase(it);
			else
				++it;
		}
		print(c);
	}

}

template <typename T>
void print(NAMESPACE::vector<T> x)
{
	std::cout << "VECTOR";
	for (NAMESPACE::vector<int>::iterator a = x.begin(); a != x.end(); a++)
		std::cout << " | " << BC << *a << NC;
	std::cout << " | " << std::endl;
}
