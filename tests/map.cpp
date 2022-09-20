#include "tests.h"
#include "../srcs/avl.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>

#define SPACE 10

using namespace std;

template <class Key, class T>
class AVLTree {

	public:
		node<Key, T> * _root;

	AVLTree() {
		_root = NULL;
	}

	~AVLTree() {
		if (_root)
		 	delete_avl(_root);
	}
	
	void delete_avl(node<Key, T> * a) {
		node<Key, T> * leftsub = a->left;
		node<Key, T> * rightsub = a->right;

		while (leftsub)
		{
			delete_avl(leftsub);
			cout << BR << "DELETED : " << leftsub->p.first << NC << endl;
			if (leftsub)
			{
				delete leftsub;
				leftsub = NULL;
			}
		}
		while (rightsub)
		{
			delete_avl(rightsub);
			cout << BR << "DELETED : " << rightsub->p.first << NC << endl;
			if (rightsub)
			{
				delete rightsub;
				rightsub = NULL;
			}
		}
		cout << BR << "DELETED : " << a->p.first << NC << endl;
		if (a)
		{
			delete a;
			a = NULL;
		}
		return ;
	}

	
	bool empty() const {
		if (!_root)
			return (true);
		return (false);
	};

	int height(node<Key, T> * r) {
		if (!r)
			return (-1);
		else
		{
			int left_h = height(r->left);
			int right_h = height(r->right);

			if (left_h > right_h)
				return (left_h + 1);
			return (right_h + 1);
		}
	};

	int balance_factor(node<Key, T> * n) {
		if (!n)
			return (-1);
		return (height(n->left) - height(n->right));
	}

	node<Key, T> * right_rotate(node<Key, T> * n) {
		node<Key, T> * n_l = n->left;
		node<Key, T> * n_l_r = n_l->right;

		n_l->right = n;
		n->left = n_l_r;
		return (n_l);
	}

	node<Key, T> * left_rotate(node<Key, T> * n) {
		node<Key, T> * n_r = n->right;
		node<Key, T> * n_r_l = n_r->left;

		n_r->left = n;
		n->right = n_r_l;
		return (n_r);
	}

	node<Key, T> * insert(node<Key, T> * r, node<Key, T> * new_node) {
		if (!r)
		{
			r = new_node;
			return (r);
		}

		if (new_node->p.first < r->p.first)
			r->left = insert(r->left, new_node);
		else if (new_node->p.first > r->p.first)
			r->right = insert(r->right, new_node);
		else {
			cout << "No duplicate values allowed!" << endl;
			return r;
		}

		int bf = balance_factor(r);
		// Left Left Case	
		if (bf > 1 && new_node->p.first < r->left->p.first)
			return right_rotate(r);

		// Right Right Case	
		if (bf < -1 && new_node->p.first > r->right->p.first)
			return left_rotate(r);

		// Left Right Case	
		if (bf > 1 && new_node->p.first > r->left->p.first) {
			r->left = left_rotate(r->left);
			return right_rotate(r);
		}

		// Right Left Case	
		if (bf < -1 && new_node->p.first < r->right->p.first) {
			r->right = right_rotate(r->right);
			return left_rotate(r);
		}

		/* return the (unchanged) node pointer */
		return r;

	}

	node<Key, T> * minValueNode(node<Key, T> * node1) {
		node<Key, T> * current = node1;
		/* loop down to find the leftmost leaf */
		while (current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	node<Key, T> * deleteNode(node<Key, T> * r, int v) {
		// base case 
		if (r == NULL) {
			return NULL;
		}
		// If the key to be deleted is smaller than the root's key, 
		// then it lies in left subtree 
		else if (v < r->p.first) {
			r->left = deleteNode(r->left, v);
		}
		// If the key to be deleted is greater than the root's key, 
		// then it lies in right subtree 
		else if (v > r->p.first) {
			r->right = deleteNode(r->right, v);
		}
		// if key is same as root's key, then This is the node to be deleted 
		else {
			// node with only one child or no child 
			if (r->left == NULL) {
				node<Key, T> * temp = r->right;
				delete r;
				return temp;
			} else if (r->right == NULL) {
				node<Key, T> * temp = r->left;
				delete r;
				return temp;
			} else {
				// node with two children: Get the inorder successor (smallest 
				// in the right subtree) 
				node<Key, T> * temp = minValueNode(r->right);
				// Copy the inorder successor's content to this node 
				r->p.first = temp->p.first;
				// Delete the inorder successor 
				r->right = deleteNode(r->right, temp->p.first);
				//deleteNode(->ight, tem->alue); 
			}
		}

		int bf = balance_factor(r);
		// Left Left Imbalance/Case or Right rotation 
		if (bf == 2 && balance_factor(r->left) >= 0)
			return right_rotate(r);
		// Left Right Imbalance/Case or LR rotation 
		else if (bf == 2 && balance_factor(r->left) == -1) {
			r->left = left_rotate(r->left);
			return right_rotate(r);
		}
		// Right Right Imbalance/Case or Left rotation	
		else if (bf == -2 && balance_factor(r->right) <= -0)
			return left_rotate(r);
		// Right Left Imbalance/Case or RL rotation 
		else if (bf == -2 && balance_factor(r->right) == 1) {
			r->right = right_rotate(r->right);
			return left_rotate(r);
		}

		return r;
	}

	node<Key, T> * iterativeSearch(int v) {
		if (_root == NULL) {
			return _root;
		} else {
			node<Key, T> * temp = _root;
			while (temp != NULL) {
				if (v == temp->p.first) {
					return temp;
				} else if (v < temp->p.first) {
					temp = temp->left;
				} else {
					temp = temp->right;
				}
			}
			return NULL;
		}
	}

	node<Key, T> * recursiveSearch(node<Key, T> * r, int val) {
		if (r == NULL || r->p.first == val)
			return r;

		else if (val < r->p.first)
			return recursiveSearch(r->left, val);

		else
			return recursiveSearch(r->right, val);
	}
/*
	void print2D(node<Key, T> * r, int space) {
		if (r == NULL) // Base case	1
			return;
		space += SPACE; // Increase distance between levels	 2
		print2D(r->right, space); // Process right child first 3 
		cout << endl;
		for (int i = SPACE; i < space; i++) // 5 
			cout << " "; // 5.1	
		cout << r->p.first << "\n"; // 6
		print2D(r->left, space); // Process left child	7
	}
	void printPreorder(node<Key, T> * r) //(current node, Left, Right) 
	{
		if (r == NULL)
			return;
		// first print data of node 
		cout << r->p.first << " ";
		// then recur on left sutree 
		printPreorder(r->left);
		// now recur on right subtree 
		printPreorder(r->right);
	}

	void printInorder(node<Key, T> * r) //	(Left, current node, Right)
	{
		if (r == NULL)
			return;
		// first recur on left child
		printInorder(r->left);
		// then print the data of node
		cout << r->p.first << " ";
		// now recur on right child
		printInorder(r->right);
	}
	void printPostorder(node<Key, T> * r) //(Left, Right, Root)
	{
		if (r == NULL)
			return;
		// first recur on left subtree 
		printPostorder(r->left);
		// then recur on right subtree 
		printPostorder(r->right);
		// now deal with the node 
		cout << r->p.first << " ";
	}

	void printGivenLevel(node<Key, T> * r, int level) {
		if (r == NULL)
			return;
		else if (level == 0)
			cout << r->p.first << " ";
		else // level > 0	
		{
			printGivenLevel(r->left, level - 1);
			printGivenLevel(r->right, level - 1);
		}
	}
	void printLevelOrderBFS(node<Key, T> * r) {
		int h = height(r);
		for (int i = 0; i <= h; i++)
			printGivenLevel(r, i);
	}
*/

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool fncomp(char lhs, char rhs) { return (lhs < rhs); }

struct classcomp{
	bool operator()(const char& lhs, const char& rhs) const {
		return (lhs < rhs);
	}
};


void map_tests()
{
	std::cout << BW << "                       _____" << NC << std::endl;
	std::cout << BW << "――――――――――――――――――――――| MAP |――――――――――――――――――――――" << NC << std::endl;
	std::cout << BW << "                       ‾‾‾‾‾" << NC << std::endl;

	// NAMESPACE::map<char,int> first;
	// first['a'] = 10;
	// first['b'] = 30;
	// first['c'] = 50;
	// first['d'] = 70;

	// NAMESPACE::map<char,int> second(first.begin(),first.end());

	// NAMESPACE::map<char,int> third(second);

	// NAMESPACE::map<char,int,classcomp> fourth;								 // class as Compare

	// bool(*fn_pt)(char,char) = fncomp;
	// NAMESPACE::map<char, int, bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	// std::cout << CY << "Test AVL" << NC << std::endl;

	// ft::pair<std::string, int> p("hello", 1);
	// avl<std::string, int> x1(p);
	// avl<std::string, int> x2("hello", 2);





	AVLTree<int, int> avl;
	int option, val;

	do {
		cout << "What operation do you want to perform? " <<
			" Select Option number. Enter 0 to exit." << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Search Node" << endl;
		cout << "3. Delete Node" << endl;
		cout << "4. Print/Traversal AVL Tree values" << endl;
		cout << "5. Height of Tree" << endl;
		cout << "6. Clear Screen" << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;
		//Node n1;
		node<int, int> * new_node = new node<int, int>();

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "AVL INSERT" << endl;
			cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
			cin >> val;
			new_node->p.first = val;
			avl._root = avl.insert(avl._root, new_node);
			cout << endl;
			break;
		case 2:
			cout << "SEARCH" << endl;
			cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
			cin >> val;
			//new_node = avl.iterativeSearch(val);
			new_node = avl.recursiveSearch(avl._root, val);
			if (new_node != NULL) {
				cout << "Value found" << endl;
			} else {
				cout << "Value NOT found" << endl;
			}
			break;
		case 3:
			cout << "DELETE" << endl;
			cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
			cin >> val;
			new_node = avl.recursiveSearch(avl._root, val);
			if (new_node != NULL) {
				avl._root = avl.deleteNode(avl._root, val);
				cout << "Value Deleted" << endl;
			} else {
				cout << "Value NOT found" << endl;
			}
			break;
		case 4:
			cout << "PRINT 2D: " << endl;
			// avl.print2D(avl.root, 5);
			// cout << endl;
			//cout <<"Print Level Order BFS: \n";
			//obj.printLevelOrderBFS(obj.root);
			//cout <<endl;
			//				cout <<"PRE-ORDER: ";
			//				obj.printPreorder(obj.root);
			//				cout<<endl;
			//				cout <<"IN-ORDER: ";
			//				obj.printInorder(obj.root);
			//				cout<<endl;
			//				cout <<"POST-ORDER: ";
			//				obj.printPostorder(obj.root);
			break;
		case 5:
			cout << "TREE HEIGHT" << endl;
			cout << "Height : " << avl.height(avl._root) << endl;
			break;
		case 6:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);



	return ;
}


// template <typename T>
// void print(NAMESPACE::map<Key, T> x, std::string s)
// {
// 	std::cout << BW << s << ":" << NC;
// 	for (typename NAMESPACE::map<Key, T>::iterator a = x.begin(); a != x.end(); a++)
// 		std::cout << " | " << BC << *a << NC;
// 	for (int i = 0; i < x.size(); i++)
// 	{
// 		std::cout << " [ " << x.at[i] << " ] = " << BC << *a << NC;
// 		std::cout << " | " << BC << *a << NC;
// 	}
// 	std::cout << " | " << std::endl;
// }
