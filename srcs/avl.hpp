#ifndef AVL_HPP
# define AVL_HPP

#include "iterators.hpp"
#include "utils.hpp"

template <class Key, class T>
class node
{

	public :


		typedef Key								key_type;
		typedef T								mapped_type;
		typedef node<const Key, T>				value_type;
		typedef value_type&						reference;
		typedef typename ft::pair<Key, T>		pair;
		typedef typename ft::pair<const Key, T>	pair_c;
		typedef const pair						const_pair;
		typedef const pair_c					const_pair_c;
		// typedef pair&							reference;
		// typedef const pair_ck					const_pair_ck;


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
				left(NULL), right(NULL), parent(NULL) {};

		template <class K, class U>
  		node(const node<const K, U> & x) : p(x), first(x.first), second(x.second),
				left(x.left), right(x.right), parent(x.parent) {};

		// template <class K, class U>
  		// node(const K & k, const U & m) : p(ft::make_pair(k, m)), first(k), second(m),
		// 		left(NULL), right(NULL), parent(NULL) {
		// };
		~node() {};

		node & operator=(const node & n) const {
			first = n.first;
			second = n.second;
			left = n.left;
			right = n.right;
			parent = n.parent;
			return (*this);
		};

		reference operator*() const {
			std::cout << BC << "dans ope* de node" << NC << std::endl;
			return (p);
		};

		friend bool operator==(const node<Key, T>& lhs, const node<Key, T>& rhs) {
			return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
		};

		friend bool operator!=(const node<Key, T>& lhs, const node<Key, T>& rhs) {
			return (!(lhs == rhs));
		};

		friend bool operator<(const node<Key, T>& lhs, const node<Key, T>& rhs) {
			return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
		};

		friend bool operator<=(const node<Key, T>& lhs, const node<Key, T>& rhs) {
			return (!(rhs < lhs));
		};

		friend bool operator>(const node<Key, T>& lhs, const node<Key, T>& rhs) {
			return (rhs < lhs);
		};

		friend bool operator>=(const node<Key, T>& lhs, const node<Key, T>& rhs) {
			return (!(lhs < rhs));
		};


		// operator pair();
		// operator pair_t();
		operator const_pair();
		// operator const_pair_c();
		// operator pair_c();

};


// template <class Key, class T>
// node<Key, T>::operator pair() {
// 	std::cout << BP << "in ope const_() node" << NC << std::endl;
// 	pair obj(first, second);
// 	// obj.first = first;
// 	// obj.second = second;
// 	return (obj);
// }

template <class Key, class T>
node<Key, T>::operator const_pair() {
	std::cout << BP << "in ope pair() node" << NC << std::endl;
	const_pair obj(first, second);
	return (obj);
}

// template <class Key, class T>
// node<Key, T>::operator const_pair_c() {
// 	std::cout << BP << "in ope pair() node" << NC << std::endl;
// 	const_pair_c obj(first, second);
// 	return (obj);
// }



template <class Key, class T>
class avl
{

	public:

		typedef std::size_t				size_type;
		typedef	node<const Key, T>		node;
		typedef	std::allocator<node>	allocator;

		node		*_root;
		size_type	_size;
		allocator	_alloc;


	avl() : _root(NULL), _size(0), _alloc() {};

	~avl() {
		if (_root)
		{
			delete_avl(_root);
			_root = NULL;
			_size = 0;
		}
	};

	void destroy_node(node * n) {
		// std::cout << UC << n->first << " DESTOYED" << NC << std::endl;
		_alloc.destroy(&n[0]);
		_alloc.deallocate(n, 1);
		n = NULL;
	};

	void delete_avl(node * n) {
		if (n)
		{
			delete_avl(n->left);
			delete_avl(n->right);
			// std::cout << BR << n->first << " DELETED" << NC << std::endl;
			destroy_node(n);
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

	node * delete_node(node * n, const Key v) {
		// std::cout << BC << "In delete_node, v = " << v << ",  n->first = " << n->first << " et n->second = " << n->second << NC << std::endl; 
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
				destroy_node(n);
				_size--;
				return (temp);
			}
			else if (!n->right)
			{
				node * temp = n->left;
				destroy_node(n);
				_size--;
				return (temp);
			}
			else 
			{
				// Copy the inorder successor's content to this node
				// node * temp = new node(*smallest_node(n->right));
				
				int side = 0;
				if (n->parent && n->parent->left == n)
					side = 1;
				else if (n->parent && n->parent->right == n)
					side = 2;
				std::cout<< UG<< "side = " << side << NC << std::endl;

				node * tmp = smallest_node(n->right);

				// std::cout << BP << "In delete_node,  n->first = " << n->first << " et n->second = " << n->second << NC << std::endl;
				// // std::cout << BR << "In delete_node,  test->first = " << test->first << " et test->second = " << test->second << NC << std::endl;
				// // std::cout << BO << "In delete_node,  test->left->first = " << test->left->first << " et test->left->second = " << test->left->second << NC << std::endl;
				// std::cout << BC << "In delete_node,  tmp->first = " << tmp->first << " et tmp->second = " << tmp->second << NC << std::endl;
				// std::cout << BC << "In delete_node,  n->right->first = " << n->right->first << " et n->right->second = " << n->right->second << NC << std::endl;

				node * tmp_l = tmp->left;
				node * tmp_r = tmp->right;
				node * tmp_p = tmp->parent;

				std::cout << BG << "In delete_node,  tmp->first = " << tmp->first << " et tmp->second = " << tmp->second << NC << std::endl;
				// std::cout << BG << "In delete_node,  tmp_l->first = " << tmp_l->first << " et tmp_l->second = " << tmp_l->second << NC << std::endl;
				// std::cout << BG << "In delete_node,  tmp_r->first = " << tmp_r->first << " et tmp_r->second = " << tmp_r->second << NC << std::endl;
				std::cout << BG << "In delete_node,  tmp_p->first = " << tmp_p->first << " et tmp_p->second = " << tmp_p->second << NC << std::endl;

				node * l = n->left;
				node * r = n->right;
				node * p = n->parent;

				std::cout << BO << "In delete_node,  n->first = " << n->first << " et n->second = " << n->second << NC << std::endl;
				std::cout << BO << "In delete_node,  l->first = " << l->first << " et l->second = " << l->second << NC << std::endl;
				std::cout << BO << "In delete_node,  r->first = " << r->first << " et r->second = " << r->second << NC << std::endl;
				std::cout << BO << "In delete_node,  p->first = " << p->first << " et p->second = " << p->second << NC << std::endl;
				tmp_p->left = n;
				n->parent = tmp_p;

				if (tmp_r)
					tmp_r->parent = n;
				n->right = tmp->right;
				n->left = tmp_l;

				if (p && side == 1)
					p->left = tmp;
				else if (p && side == 2)
					p->right = tmp;
				tmp->parent = p;

				if (l)
					l->parent = tmp;
				tmp->left = l;

				if (r)
					r->parent = tmp;
				// tmp = n;

				std::cout << BG << "In delete_node,  tmp->first = " << tmp->first << " et tmp->second = " << tmp->second << NC << std::endl;
				// std::cout << BG << "In delete_node,  tmp_l->first = " << tmp_l->first << " et tmp_l->second = " << tmp_l->second << NC << std::endl;
				// std::cout << BG << "In delete_node,  tmp_r->first = " << tmp_r->first << " et tmp_r->second = " << tmp_r->second << NC << std::endl;
				std::cout << BG << "In delete_node,  tmp_p->first = " << tmp_p->first << " et tmp_p->second = " << tmp_p->second << NC << std::endl;

				std::cout << BO << "In delete_node,  n->first = " << n->first << " et n->second = " << n->second << NC << std::endl;
				std::cout << BO << "In delete_node,  l->first = " << l->first << " et l->second = " << l->second << NC << std::endl;
				std::cout << BO << "In delete_node,  r->first = " << r->first << " et r->second = " << r->second << NC << std::endl;
				std::cout << BO << "In delete_node,  p->first = " << p->first << " et p->second = " << p->second << NC << std::endl;

				// test->left->right = n;
				// std::cout << BP << "In delete_node,  n->first = " << n->first << " et n->second = " << n->second << NC << std::endl;
				// // std::cout << BR << "In delete_node,  test->first = " << test->first << " et test->second = " << test->second << NC << std::endl;
				// // std::cout << BO << "In delete_node,  test->left->first = " << test->left->first << " et test->left->second = " << test->left->second << NC << std::endl;
				// // std::cout << BY << "In delete_node,  test->left->right->first = " << test->left->right->first << " et test->left->right->second = " << test->left->right->second << NC << std::endl;
				// std::cout << BC << "In delete_node,  tmp->first = " << tmp->first << " et tmp->second = " << tmp->second << NC << std::endl;
				// std::cout << BC << "In delete_node,  n->right->first = " << n->right->first << " et n->right->second = " << n->right->second << NC << std::endl;

				// Delete the inorder successor 
				tmp = delete_node(n->right, n->first);
				
				// node with two children: Get the inorder successor (smallest in the right subtree)
				// int side = 0;
				// if (n->parent && n->parent->left == n)
				// 	side = 1;
				// if (n->parent && n->parent->right == n)
				// 	side = 2;

				// node * temp = new node(*smallest_node(n->right));
				// node * temp_l = temp->left;
				// node * temp_r = temp->right;
				// node * temp_p = temp->parent;
				// node * l = n->left;
				// node * r = n->right;
				// node * p = n->parent;
				// // Copy the inorder successor's content to this node
				// _alloc.destroy(&n[0]);
				// _alloc.construct(&n[0], node(ft::make_pair(temp->first, temp->second)));
				// n->left = l;
				// n->right = r;
				// n->parent = p;
				// l->parent = n;
				// r->parent = n;
				// if (p && side == 1)
				// 	p->left = n;
				// if (p && side == 2)
				// 	p->right = n;

				// // n->first = temp->first;
				// // Delete the inorder successor 
				// n->right = delete_node(n->right, temp->first);
				// if (temp)
				// 	destroy_node(temp);
			}
		}
		
		std::cout << UO << "ARRIVE ICI" << NC << std::endl;

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

	node * right_rotate(node * n) {
		node * n_l = n->left;
		node * n_l_r = n_l->right;
		node * n_p = n->parent;

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

		n_r->parent = n_p;
		if (n_r_l)
			n_r_l->parent = n;
		n->parent = n_r;
		n_r->left = n;
		n->right = n_r_l;
		return (n_r);
	};
	
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