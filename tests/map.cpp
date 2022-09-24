#include "tests.h"
// #include "../srcs/avl.hpp"


// bool fncomp(char lhs, char rhs) { return (lhs < rhs); }

// struct classcomp{
// 	bool operator()(const char& lhs, const char& rhs) const {
// 		return (lhs < rhs);
// 	}
// };

void map_tests()
{
	std::cout << BW << "                       _____" << NC << std::endl;
	std::cout << BW << "――――――――――――――――――――――| MAP |――――――――――――――――――――――" << NC << std::endl;
	std::cout << BW << "                       ‾‾‾‾‾" << NC << std::endl;

	// std::cout << CY << "Test AVL" << NC << std::endl;

	// ft::pair<std::string, int> p("hello", 1);
	// avl<std::string, int> x1(p);
	// avl<std::string, int> x2("hello", 2);

	/********* testing constructors *********/
	std::cout << UG << "Testing constructors" << NC << std::endl;
	NAMESPACE::map<char,int> first;
	// ft::map<int, int>::iterator it;

	first.insert(NAMESPACE::pair<char, int>('a', 100));
	first.insert(NAMESPACE::pair<char, int>('b', 200));
	first.insert(NAMESPACE::pair<char, int>('c', 300));
	std::cout << UG << "ICI OK" << NC << std::endl;
	// print_map(first, "first");
	NAMESPACE::map<char, int>::iterator a = first.begin();
	NAMESPACE::map<char, int>::iterator b = first.end();
	for (; a != b; a++)
		std::cout << " [ " << YE << a->first << NC << " ] = " << BC << a->second << NC << " |";
	
	std::cout << std::endl;
	NAMESPACE::map<char, int>::reverse_iterator c = first.rbegin();
	NAMESPACE::map<char, int>::reverse_iterator d = first.rend();
	for (; c != d; c++)
		std::cout << " [ " << YE << c->first << NC << " ] = " << BC << c->second << NC << " |";
	// first['a'] = 10;
	// first['b'] = 30;
	// first['c'] = 50;
	// first['d'] = 70;

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
	{
		std::cout << UG << "\nTesting iterators" << NC << std::endl;
	}
	
	/*std::cout << CY << "Test AVL" << NC << std::endl;

	avl<int, int> avl;
	int option, val;

	do {
		std::cout << "What operation do you want to perform? " <<
			" Select Option number. Enter 0 to exit." << std::endl;
		std::cout << "1. Insert Node" << std::endl;
		std::cout << "2. Search Node" << std::endl;
		std::cout << "3. Delete Node" << std::endl;
		std::cout << "4. Print/Traversal AVL Tree values" << std::endl;
		std::cout << "5. Height of Tree" << std::endl;
		std::cout << "6. Clear Screen" << std::endl;
		std::cout << "0. Exit Program" << std::endl;

		std::cin >> option;
		//Node n1;
		node<int, int> * new_node = new node<int, int>();

		switch (option) {
		case 0:
			break;
		case 1:
			std::cout << "AVL INSERT" << std::endl;
			std::cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
			std::cin >> val;
			new_node->p.first = val;
			avl._root = avl.insert_node(avl._root, new_node);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "SEARCH" << std::endl;
			std::cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
			std::cin >> val;
			//new_node = avl.iterativeSearch(val);
			new_node = avl.recursive_search(avl._root, val);
			if (new_node != NULL) {
				std::cout << "Value found" << std::endl;
			} else {
				std::cout << "Value NOT found" << std::endl;
			}
			break;
		case 3:
			std::cout << "DELETE" << std::endl;
			std::cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
			std::cin >> val;
			new_node = avl.recursive_search(avl._root, val);
			if (new_node != NULL) {
				avl._root = avl.delete_node(avl._root, val);
				std::cout << "Value Deleted" << std::endl;
			} else {
				std::cout << "Value NOT found" << std::endl;
			}
			break;
		case 4:
			std::cout << "PRINT 2D: " << std::endl;
			// avl.print2D(avl.root, 5);
			// cout << std::endl;
			//cout <<"Print Level Order BFS: \n";
			//obj.printLevelOrderBFS(obj.root);
			//cout <<endl;
			//				std::cout <<"PRE-ORDER: ";
			//				obj.printPreorder(obj.root);
			//				std::cout<<endl;
			//				std::cout <<"IN-ORDER: ";
			//				obj.printInorder(obj.root);
			//				std::cout<<endl;
			//				std::cout <<"POST-ORDER: ";
			//				obj.printPostorder(obj.root);
			break;
		case 5:
			std::cout << "TREE HEIGHT" << std::endl;
			std::cout << "Height : " << avl.height(avl._root) << std::endl;
			break;
		case 6:
			system("cls");
			break;
		default:
			std::cout << "Enter Proper Option number " << std::endl;
		}

	} while (option != 0);
*/


	return ;
}

template <class Key, class T>
void print_map(NAMESPACE::map<Key, T> x, std::string s)
{
	std::cout << BY << "in print fct" << std::endl;
	std::cout << BW << s << ":" << NC;
	for (typename NAMESPACE::map<Key, T>::iterator a = x.begin(); a != x.end(); a++)
		std::cout << " [ " << YE << a->first << NC << " ] = " << BC << a->second << NC << " |";
	std::cout << std::endl;
}

// void print_map(NAMESPACE::map<char, int> x, std::string s)
// {
// 	std::cout << BY << "in print fct" << std::endl;
// 	// std::cout << BW << s << ":" << NC;
// 	(void)x;
// 	(void)s;
// 	// for (typename NAMESPACE::map<Key, T>::iterator a = x.begin(); a != x.end(); a++)
// 	// 	std::cout << " [ " << YE << a->first << NC << " ] = " << BC << a->second << NC << " |";
// 	// std::cout << std::endl;
// }