#ifndef AVL_HPP
# define AVL_HPP

template <class Key, class T>
class node
{
	public :

		Key		key;
		T		value;
		node	*left;
		node	*right;

		node(Key k, T v) : key(k), value(v), left(NULL), right(NULL) {};

		//node(node x) : key(x.k), value(x.v), left(NULL), right(NULL) {};


};

template <class Key, class T>
class avl
{

class node;

	private :

		node *_root;


	public :

		avl() : _root(NULL) {};

		avl(Key k, T v) : _root(k, v) {};

		bool empty() const {
			if (!_root)
		    	return (true);
			return (false);
		};

		void add_node(Key k, T v);

		void delete_node(Key k);

		void search_node(Key k);

		void rotation();


};

#endif