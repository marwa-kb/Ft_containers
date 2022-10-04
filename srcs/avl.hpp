#ifndef AVL_HPP
# define AVL_HPP

#include "utils.hpp"
#include "iterators.hpp"

namespace ft
{
	template <class Key, class T, class Compare, class Allocator>
	class map;
	
	template <class Iterator, class Key, class T, class Compare>
	class m_iterator;
}

namespace ft
{
	template <class Key, class T>
	class node : public ft::pair<Key, T>
	{

		public :

			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::node<const Key, T>			value_type;
			typedef value_type&						reference;
			typedef typename ft::pair<const Key, T>	pair;
			typedef const pair						const_pair;

			node		*left;
			node		*right;
			node		*parent;


			node()
					: pair(), left(NULL), right(NULL), parent(NULL) {};

			node(const pair & x)
					:  pair(x), left(NULL), right(NULL), parent(NULL) {};

			node(const key_type & k, const mapped_type & m)
					:  pair (ft::make_pair(k, m)), left(NULL), right(NULL), parent(NULL) {};

			node(const pair & x, node * l, node * r, node * p)
					: pair(x), left(l), right(r), parent(p) {};

			template <class K, class U>
			node(const node<const K, U> & x)
					: pair(x),	left(x.left), right(x.right), parent(x.parent) {};

			~node() {};


			node & operator=(const node & n) {
				*this = n;
				left = n.left;
				right = n.right;
				parent = n.parent;
				return (*this);
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

	};


	template <class Key, class T, class Compare>
	class avl
	{

		public:

			typedef std::size_t						size_type;
			typedef	ft::node<const Key, T>			node;
			typedef	std::allocator<node>			allocator;
			typedef	Compare							key_comp;

			node		*_root;
			size_type	_size;
			allocator	_alloc;
			key_comp	_comp;


			avl() : _root(NULL), _size(0), _alloc(), _comp() {};

			~avl() {
				if (_root)
				{
					delete_avl(_root);
					_root = NULL;
					_size = 0;
				}
			};

			void destroy_node(node * n) {
				_alloc.destroy(&n[0]);
				_alloc.deallocate(n, 1);
				n = NULL;
			};

			void delete_avl(node * n) {
				if (n)
				{
					delete_avl(n->left);
					delete_avl(n->right);
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

			int height(node * n) const {
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

			int balance_factor(node * n) const {
				if (!n)
					return (-1);
				return (height(n->left) - height(n->right));
			};

			node * smallest_node(node * n) const {	//loop down to find the leftmost leaf
				node * current = n;
				while (current && current->left)
					current = current->left;
				return (current);
			};

			node * biggest_node(node * n) const {	//loop down to find the righftmost leaf
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
				if (_comp(new_node->first, n->first))
					n->left = insert_node(n->left, new_node, n, ok);
				else if (_comp(n->first, new_node->first))
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
				if (bf > 1 && _comp(new_node->first, n->left->first))		//left left
					return (right_rotate(n));
				if (bf < -1 && _comp(n->right->first, new_node->first))	//right right
					return (left_rotate(n));
				if (bf > 1 && _comp(n->left->first, new_node->first))		//left right
				{
					n->left = left_rotate(n->left);
					return (right_rotate(n));
				}
				if (bf < -1 && _comp(new_node->first, n->right->first))	// right left 
				{
					n->right = right_rotate(n->right);
					return (left_rotate(n));
				}
				return (n);
			};

			node * delete_node(node * n, const Key v) {
				if (!n)
					return (NULL);
				else if (_comp(v, n->first))
					n->left = delete_node(n->left, v);
				else if (_comp(n->first, v))
					n->right = delete_node(n->right, v);
				else
				{
					if (!n->left) // node with only one child or no child
					{
						node * tmp = n->right;
						if (n->right)
							n->right->parent = n->parent;
						destroy_node(n);
						_size--;
						return (tmp);
					}
					else if (!n->right)
					{
						node * tmp = n->left;
						if (n->left)
							n->left->parent = n->parent;
						destroy_node(n);
						_size--;
						return (tmp);
					}
					else 
					{
						// node with two children 
						int side = 0;
						if (n->parent && n->parent->left == n)
							side = 1;
						else if (n->parent && n->parent->right == n)
							side = 2;

						node * tmp = smallest_node(n->right);
						int direct = 0;
						if (tmp == n->right)
							direct = 1;

						node * tmp_r = tmp->right;
						node * tmp_p = tmp->parent;

						node * l = n->left;
						node * r = n->right;
						node * p = n->parent;

						_alloc.destroy(&n[0]);
						if (direct)
						{
							_alloc.construct(&n[0], node(ft::make_pair(tmp->first, tmp->second), l, tmp_r, p));
							if (n->right)
								n->right->parent = n;
						}
						else
						{
							_alloc.construct(&n[0], node(ft::make_pair(tmp->first, tmp->second), l, r, p));
							if (tmp_r)
								tmp_r->parent = tmp_p;
							if (tmp_p)
								tmp_p->left = tmp_r;
						}

						if (p && side == 1)
							p->left = n;
						else if (p && side == 2)
							p->right = n;

						if (l)
							l->parent = n;
						destroy_node(tmp);
						_size--;
					}
				}

				int bf = balance_factor(n);
				if (bf == 2 && balance_factor(n->left) >= 0)			// Left Left Case or Right rotation
					return (right_rotate(n));
				else if (bf == 2 && balance_factor(n->left) == -1)		// Left Right Case or LR rotation
				{
					n->left = left_rotate(n->left);
					return (right_rotate(n));
				}
				else if (bf == -2 && balance_factor(n->right) <= -0)	// Right Right Case or Left rotation
					return (left_rotate(n));
				else if (bf == -2 && balance_factor(n->right) == 1)		// Right Left Case or RL rotation 
				{
					n->right = right_rotate(n->right);
					return (left_rotate(n));
				}
				return (n);
			};

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
						else if (_comp(val, temp->first))
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
				else if (_comp(val, r->first))
					return (recursive_search(r->left, val));
				return (recursive_search(r->right, val));
			};

	};
}

#endif