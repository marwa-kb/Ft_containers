#ifndef AVL_HPP
# define AVL_HPP

#include "utils.hpp"

template <class Key, class T>
class node
{
	public :


		typedef Key							key_type;
		typedef T							mapped_type;
		typedef ft::pair<const Key, T>		value_type;// /!\ pareil
		typedef std::size_t					size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
		typedef typename std::allocator<T>	allocator_type;
		typedef typename ft::pair<Key, T>	pair;


	private :

		allocator_type	_alloc;


	public :

		pair		p;
		key_type	first;
		mapped_type	second;	
		node		*left;
		node		*right;
		node		*parent;

		node() : p(pair()), first(), second(), left(NULL), right(NULL), parent(NULL) {};

		node(const pair & x) : p(x), first(x.first), second(x.second), left(NULL), right(NULL), parent(NULL) {};

		node(const node<Key, T> & x) : p(x.p), first(x.first), second(x.second), left(x.left), right(x.right), parent(x.parent) {};

		~node() {};

};

template <class Key, class T>
class avl
{

	public:

		typedef std::size_t	size_type;

		node<Key, T> *	_root;
		size_type		_size;


	avl() : _root(NULL), _size(0) {};

	avl(const avl & a) : _root(NULL), _size(a._size) {
		node<Key, T>* n1 = a._root;
		node<Key, T>* n2 = _root;

		while (n1)
		{
			while (n1->left)
			{
				node<Key, T> *n3 = new node<Key, T>(n1->p);
				insert_node(n2, n3);
				n1 = n1->left;
			}
			while (n1->right)
			{
				node<Key, T> *n4 = new node<Key, T>(n1->p);
				insert_node(n2, n4);
				n1 = n1->right;
			}
		}
	};

	~avl() {
		if (_root)
			delete_avl(_root);
		//delete _root;//?
	};
	
	void delete_avl(node<Key, T> * n) {
		if (n)
		{
			delete_avl(n->left);
			delete_avl(n->right);
			std::cout << BR << n->p.first << " DELETED" << NC << std::endl;
			delete n;
		}
		n = NULL;
	};

	
	bool empty() const {
		if (!_root)
			return (true);
		return (false);
	};

	size_type size() const {
		return (_size);
	};

	int height(node<Key, T> * n) {
		if (!n)
			return (-1);
		else
		{
			int left_h = height(n->left);
			int right_h = height(n->right);

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

	node<Key, T> * insert_node(node<Key, T> * n, node<Key, T> * new_node, bool *ok = NULL) {
		if (!n)
		{
			n = new_node;
			_size++;
			if (ok)
				*ok = true;
			return (n);
		}
		if (new_node->p.first < n->p.first)
			n->left = insert_node(n->left, new_node);
		else if (new_node->p.first > n->p.first)
			n->right = insert_node(n->right, new_node);
		else
		{
			if (ok)
				*ok = false;
			return (n);
		}

		int bf = balance_factor(n);
		if (bf > 1 && new_node->p.first < n->left->p.first)		//left left
			return (right_rotate(n));
		if (bf < -1 && new_node->p.first > n->right->p.first)	//right right
			return (left_rotate(n));
		if (bf > 1 && new_node->p.first > n->left->p.first)		//left right
		{
			n->left = left_rotate(n->left);
			return (right_rotate(n));
		}
		if (bf < -1 && new_node->p.first < n->right->p.first)	// right left 
		{
			n->right = right_rotate(n->right);
			return (left_rotate(n));
		}
		if (ok)
			*ok = true;
		return (n);
	};

	node<Key, T> * smallest_node(node<Key, T> * n) {	//loop down to find the leftmost leaf
		node<Key, T> * current = n;
		while (current && current->left)
			current = current->left;
		return (current);
	}

	node<Key, T> * delete_node(node<Key, T> * n, Key v) {
		// base case
		if (!n)
			return (NULL);
		else if (v < n->p.first)
			n->left = delete_node(n->left, v);
		else if (v > n->p.first)
			n->right = delete_node(n->right, v);
		else
		{
			// node with only one child or no child 
			if (!n->left)
			{
				node<Key, T> * temp = n->right;
				delete n;	// /!\ remplacer delete par allocator 
				return (temp);
			}
			else if (!n->right)
			{
				node<Key, T> * temp = n->left;
				delete n;	// /!\ remplacer delete par allocator 
				return (temp);
			}
			else 
			{
				// node with two children: Get the inorder successor (smallest 
				// in the right subtree) 
				node<Key, T> * temp = smallest_node(n->right);
				// Copy the inorder successor's content to this node 
				n->p.first = temp->p.first;
				// Delete the inorder successor 
				n->right = delete_node(n->right, temp->p.first);
				//deleteNode(->ight, tem->alue); 
			}
		}

		int bf = balance_factor(n);
		// Left Left Imbalance/Case or Right rotation 
		if (bf == 2 && balance_factor(n->left) >= 0)
			return (right_rotate(n));
		// Left Right Imbalance/Case or LR rotation 
		else if (bf == 2 && balance_factor(n->left) == -1) {
			n->left = left_rotate(n->left);
			return (right_rotate(n));
		}
		// Right Right Imbalance/Case or Left rotation	
		else if (bf == -2 && balance_factor(n->right) <= -0)
			return (left_rotate(n));
		// Right Left Imbalance/Case or RL rotation 
		else if (bf == -2 && balance_factor(n->right) == 1) {
			n->right = right_rotate(n->right);
			return (left_rotate(n));
		}
		return (n);
	}

	void clear() {
		node<Key, T> * temp = _root->left;
		while (temp)
		{
			temp = temp->left;

		}
		
		_size = 0;
	};

	node<Key, T> * iterative_search(const Key & val) const {
		if (!_root)
			return (NULL);
		else
		{
			node<Key, T> * temp = _root;
			while (temp)
			{
				if (val == temp->p.first)
					return (temp);
				else if (val < temp->p.first)
					temp = temp->left;
				else
					temp = temp->right;
			}
			return (NULL);
		}
	}

	node<Key, T> * recursive_search(node<Key, T> * r, const Key & val) const {
		if (!r || r->p.first == val)
			return (r);
		else if (val < r->p.first)
			return (recursive_search(r->left, val));
		return (recursive_search(r->right, val));
	}
/*
	void print2D(node<Key, T> * r, int space) {
		if (r == NULL) // Base case	1
			return;
		space += SPACE; // Increase distance between levels	 2
		print2D(r->right, space); // Process right child first 3 
		std::cout << std::endl;
		for (int i = SPACE; i < space; i++) // 5 
			std::cout << " "; // 5.1	
		std::cout << r->p.first << "\n"; // 6
		print2D(r->left, space); // Process left child	7
	}
	void printPreorder(node<Key, T> * r) //(current node, Left, Right) 
	{
		if (r == NULL)
			return;
		// first print data of node 
		std::cout << r->p.first << " ";
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
		std::cout << r->p.first << " ";
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
		std::cout << r->p.first << " ";
	}

	void printGivenLevel(node<Key, T> * r, int level) {
		if (r == NULL)
			return;
		else if (level == 0)
			std::cout << r->p.first << " ";
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
/*

template <class Key, class T>
class avl
{

	public :

		typedef std::size_t					size_type;
		// typedef std::ptrdiff_t				difference_type;
		typedef typename std::allocator<T>	allocator;
		typedef typename ft::pair<Key, T>	pair;
		// typedef pair						value_type;



	private :

		node<Key, T>	*_root;
		allocator		_alloc;
		size_type		_size;


	public :


		avl() : _root(NULL), _size(0) {};
		
		// avl(const pair & p) {
			// _root = create_node(p);
			// _size = 1;
		// };

		// avl(const Key & k, const T & v) {
			// _root = create_node(pair(k, v));
			// _size = 1;
		// };

		avl(const avl & x) : _root(x._root) {}; // PAS DU TOUT FINI

		~avl() {
			if (_root)
			{
				// _alloc.destroy(*_root);
				// _alloc.deallocate(_root, sizeof(_root));
				delete _root; // /!\ A CHANGER ABSOLUMENT
			}
		};

		bool empty() const {
			if (!_root)
				return (true);
			return (false);
		};

		size_type size() const {
			return (_size);
		};


		void insert_node(const pair & x) {
			node<Key, T> *a = create_node(x);
			if (!_root)
				_root = a;
			else
			{
				if (x.first > _root->p.first)
					_root->right = a;
				else
					_root->left = a;
			}
			_size++;
		};

		node<Key, T> * create_node(const pair & x) {
			node<Key, T> *a = new node<Key, T>(x); // /!\ A CHANGER ABSOLUMENT
			//_alloc.construct(a, node<Key, T>(x));
			return (a);
		};

		void delete_node(Key k) {
			search_node(k);
			_size--;
		};

		void search_node(Key k);

		void rotation();


};
*/
#endif