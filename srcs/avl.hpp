#ifndef AVL_HPP
# define AVL_HPP

#include "utils.hpp"

template <class Key, class T>
class node
{
	public :

		typedef typename std::allocator<T>	allocator;
		typedef typename ft::pair<Key, T>	pair;


	private :

		allocator	_alloc;


	public :

		pair				p;
		node				*left;
		node				*right;

		node(const pair & x) : p(x), left(NULL), right(NULL) {};

		node(const node<Key, T> & x) : p(x.p), left(NULL), right(NULL) {};

		~node() {};

		




};

template <class Key, class T>
class avl
{

class node;

	public :

		typedef typename std::allocator<T>	allocator;
		typedef typename ft::pair<Key, T>	pair;


	private :

		node		*_root;
		allocator	_alloc;


	public :


		avl() : _root(NULL) {};
		
		avl(const pair & p) {
			_root = create_node(p);
		};

		avl(const Key & k, const T & v) {
			_root = create_node(pair(k, v));
		};

		avl(const avl & x) : _root(x._root) {};

		~avl() {
			if (_root)
			{
				_alloc.destroy(*_root);
				_alloc.deallocate(_root, sizeof(_root));
			}
		};

		bool empty() const {
			if (!_root)
		    	return (true);
			return (false);
		};

		void insert_node(const pair & x) {
			node *a = create_node(x);
			if (!_root)
				_root = a;
			else
			{
				if (x.first > _root.p.first)
					_root.right = a;
				else
					_root.left = a;
			}
		};

		node * create_node(const pair & x) {
			node *a = _alloc.allocate(*a);
			_alloc.construct(a, node(x));
			return (a);
		};

		void delete_node(Key k);

		void search_node(Key k);

		void rotation();


};

#endif