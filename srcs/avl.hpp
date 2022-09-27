#ifndef AVL_HPP
# define AVL_HPP

#include "utils.hpp"
#include "iterators.hpp"

template <class Key, class T>
class node
{
	public :


		typedef Key								key_type;
		typedef T								mapped_type;
		typedef node<const Key, T>				value_type;
		// typedef value_type&						reference;
		typedef typename ft::pair<Key, T>		pair;
		typedef typename ft::pair<const Key, T>	pair_c;
		typedef const pair						const_pair;
		typedef const pair_c					const_pair_c;
		typedef pair_c&							reference;
		// typedef const pair_ck					const_pair_ck;


	private :

		// allocator_type	_alloc;


	public :

		pair		p;
		key_type	first;
		mapped_type	second;	
		node		*left;
		node		*right;
		node		*parent;

		node() : p(pair()), first(), second(),
				left(NULL), right(NULL), parent(NULL) {};

		node(const pair & x) : p(x), first(x.first), second(x.second),
				left(NULL), right(NULL), parent(NULL) {};

  		node(const key_type & k, const mapped_type & m) : p(ft::make_pair(k, m)), first(k), second(m),
				left(NULL), right(NULL), parent(NULL) {
		};

		template <class K, class U>
  		node(const node<K, U> & x) : p(x), first(x.first), second(x.second),
				left(NULL), right(NULL), parent(NULL) {
		};

		template <class K, class U>
  		node(const K & k, const U & m) : p(ft::make_pair(k, m)), first(k), second(m),
				left(NULL), right(NULL), parent(NULL) {
		};
		~node() {};


		reference operator*() const {
			std::cout << BC << "dans ope* de node" << NC << std::endl;
			return (p);
		};


		// operator pair();
		// operator pair_t();
		// operator const_pair();
		operator const_pair_c();
		// operator pair_c();

};
// 
// template <class Key, class T>
// node<Key, T>::operator pair() {
	// std::cout << BP << "in ope pair() node" << NC << std::endl;
	// pair obj(first, second);
	// return (obj);
// }

// template <class Key, class T>
// node<Key, T>::operator const_pair() {
// 	std::cout << BP << "in ope pair() node" << NC << std::endl;
// 	const_pair obj(first, second);
// 	return (obj);
// }

template <class Key, class T>
node<Key, T>::operator const_pair_c() {
	std::cout << BP << "in ope pair() node" << NC << std::endl;
	const_pair_c obj(first, second);
	return (obj);
}



template <class Key, class T>
class avl
{

	public:

		typedef std::size_t			size_type;
		typedef	node<const Key, T>	node;

		node		*_root;
		size_type	_size;


	avl() : _root(NULL), _size(0) {};

	// avl(const avl & a) : _root(NULL), _size(a._size) {
	// 	std::cout << BO << "avl copy constructor" << NC << std::endl;

	// 	node<Key, T>* n1 = a._root;
	// 	node<Key, T>* n2 = _root;

	// 	while (n1)
	// 	{
	// 		while (n1->left)
	// 		{
	// 			node<Key, T> *n3 = new node<Key, T>(n1->p);
	// 			insert_node(n2, n3);
	// 			n1 = n1->left;
	// 		}
	// 		while (n1->right)
	// 		{
	// 			node<Key, T> *n4 = new node<Key, T>(n1->p);
	// 			insert_node(n2, n4);
	// 			n1 = n1->right;
	// 		}
	// 	}
	// };

	~avl() {
		if (_root)
		{
			delete_avl(_root);
			_root = NULL;
			_size = 0;
		}
	};

	// node<Key, T>* create_node(bool x) {
	// 	node<Key, T> *n = new node<Key, T>(x);
	// 	return (n);
	// }
	
	
	void delete_avl(node * n) {
		if (n)
		{
			delete_avl(n->left);
			delete_avl(n->right);
			// std::cout << BR << n->first << " DELETED" << NC << std::endl;
			delete n;
		}
		n = NULL;
	};
	
	void clear() {
		delete_avl(_root);
		_root = NULL;
		_size = 0;
	};

	bool empty() const {
		if (!_root)
			return (true);
		return (false);
	};

	size_type size() const {
		return (_size);
	};

	int height(node * n) {
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

	int balance_factor(node * n) {
		if (!n)
			return (-1);
		return (height(n->left) - height(n->right));
	};

	node * right_rotate(node * n) {
		node * n_l = n->left;
		node * n_l_r = n_l->right;
		node * n_p = n->parent;
		// std::cout << UR << "RIGHT ROTATE" << NC << std::endl;
		// std::cout << UO << "data of node = " << n->first << " et " << n->second << NC << std::endl;

		n_l->parent = n_p;
		if (n_l_r)
			n_l_r->parent = n;
		n->parent = n_l;
		n_l->right = n;
		n->left = n_l_r;
		return (n_l);
	};

	node * left_rotate(node * n) {
		node * n_r = n->right;
		node * n_r_l = n_r->left;
		node * n_p = n->parent;

		// std::cout << UR << "LEFT ROTATE" << NC << std::endl;
		// std::cout << UO << "data of node = " << n->first << " et " << n->second << NC << std::endl;

		n_r->parent = n_p;
		if (n_r_l)
			n_r_l->parent = n;
		n->parent = n_r;
		n_r->left = n;
		n->right = n_r_l;
		return (n_r);
	};

	node * insert_node(node * n, node * new_node, node * par = NULL, bool *ok = NULL) {
		if (!n)
		{
			n = new_node;
			new_node->parent = par;
			_size++;
			if (ok)
				*ok = true;
			return (n);
		}
		if (new_node->first < n->first)
			n->left = insert_node(n->left, new_node, n, ok);
		else if (new_node->first > n->first)
			n->right = insert_node(n->right, new_node, n, ok);
		else
		{
			if (ok)
				*ok = false;
			return (n);
		}

		if (ok && !*ok)
			return (n);
		int bf = balance_factor(n);
		if (bf > 1 && new_node->first < n->left->first)		//left left
			return (right_rotate(n));
		if (bf < -1 && new_node->first > n->right->first)	//right right
			return (left_rotate(n));
		if (bf > 1 && new_node->first > n->left->first)		//left right
		{
			n->left = left_rotate(n->left);
			return (right_rotate(n));
		}
		if (bf < -1 && new_node->first < n->right->first)	// right left 
		{
			n->right = right_rotate(n->right);
			return (left_rotate(n));
		}
		return (n);
	};

	node * smallest_node(node * n) {	//loop down to find the leftmost leaf
		node * current = n;
		while (current && current->left)
			current = current->left;
		return (current);
	};

	node * biggest_node(node * n) {		//loop down to find the righftmost leaf
		node * current = n;
		while (current && current->right)
			current = current->right;
		return (current);
	};

	node * delete_node(node * n, const Key v) {
		// base case
		if (!n)
			return (NULL);
		else if (v < n->first)
			n->left = delete_node(n->left, v);
		else if (v > n->first)
			n->right = delete_node(n->right, v);
		else
		{
			// node with only one child or no child 
			if (!n->left)
			{
				node * temp = n->right;
				delete n;	// /!\ remplacer delete par allocator 
				_size--;
				return (temp);
			}
			else if (!n->right)
			{
				node * temp = n->left;
				delete n;	// /!\ remplacer delete par allocator 
				_size--;
				return (temp);
			}
			else 
			{
				// node with two children: Get the inorder successor (smallest 
				// in the right subtree) 
				node * temp = smallest_node(n->right);
				// Copy the inorder successor's content to this node
				Key temp1 = n->first;
				T temp2 = n->second;
				delete n;
				n = new node(temp1, temp2);
				// n->first = temp->first;
				// Delete the inorder successor 
				n->right = delete_node(n->right, temp->first);
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

	node * iterative_search(const Key & val) const {
		if (!_root)
			return (NULL);
		else
		{
			node * temp = _root;
			while (temp)
			{
				if (val == temp->first)
					return (temp);
				else if (val < temp->first)
					temp = temp->left;
				else
					temp = temp->right;
			}
			return (NULL);
		}
	};

	node * recursive_search(node * r, const Key & val) const {
		if (!r || r->first == val)
			return (r);
		else if (val < r->first)
			return (recursive_search(r->left, val));
		return (recursive_search(r->right, val));
	};

	// avl<Key, T> * avl_copy(avl<Key, T> * a)
	// {
	// 	avl<Key, T> * b = new avl<Key, T>();
	// 	ft::m_iterator<node<Key, T>*, Key, T> it1(a->smallest_node());
	// 	ft::m_iterator<node<Key, T>*, Key, T> it2(a->biggest_node());
	// 	for (; it1 != it2; it1++)
	// 		b->insert_node(it1.current, b->_root, NULL, NULL);
	// 	b->insert_node(it1.current, b->_root, NULL, NULL);
	// 	return (b);
	// }

	// friend bool operator==(const avl<Key, T> & lhs, const avl<Key, T> & rhs) {
	// 	ft::m_iterator<node<Key, T>*, Key, T> x;
	// 	return ((lhs.tree == rhs.tree) && (lhs.current == rhs.current));
	// };


};

#endif