#ifndef AVL_HPP
# define AVL_HPP

#include "utils.hpp"

template <class Key, class T>
class node
{
	public :


		// typedef std::size_t					size_type;
		// typedef std::ptrdiff_t				difference_type;
		typedef typename std::allocator<T>	allocator;
		typedef typename ft::pair<Key, T>	pair;
		// typedef pair						value_type;



	private :

		allocator	_alloc;


	public :

		pair	p;
		node	*left;
		node	*right;

		node() : p(pair()), left(NULL), right(NULL) {};

		node(const pair & x) : p(x), left(NULL), right(NULL) {};

		node(const node<Key, T> & x) : p(x.p), left(x.left), right(x.right) {};

		~node() {};

};


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

#endif