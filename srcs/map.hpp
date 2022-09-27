#ifndef MAP_HPP
# define MAP_HPP

#include <string>
#include "avl.hpp"
#include "utils.hpp"
#include "iterators.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > // /!\ ft::pair au lieu de stdf
	class map
	{

		public:

			typedef Key	 														key_type;
			typedef T	 														mapped_type;
			typedef Compare	 													key_compare;
			typedef ft::pair<const Key, T>										value_type;// /!\ pareil
			typedef Allocator	 												allocator_type;
			typedef std::size_t													size_type;
			typedef std::ptrdiff_t												difference_type;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef value_type*													pointer;
			typedef const value_type*											const_pointer;
			typedef typename ft::m_iterator<node<Key, T>*, Key, T>				iterator;
			typedef typename ft::m_iterator<const node<const Key, T>*, Key, T>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;


			class value_compare : public ft::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {};
			
				public:
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					typedef bool		result_type;

					bool operator()(const value_type& x, const value_type& y) const {
						return (comp(x.first, y.first));
					};
			};
			

		private :

			key_compare		_comp;
			allocator_type	_alloc;
			avl<Key, T>		*_tree;


		public :

			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
				: _comp(comp), _alloc(alloc) {
					_tree = new avl<Key, T>(); // /!\ allocator
					// _tree = _alloc.allocate();
					// for (size_type i = 0; i < n; i++)
						// _alloc.construct(&_tab[i], value_type(val));
				};

			// template <class InputIterator>
			// map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());

			map(const map<Key, T, Compare, Allocator>& x)
				: _comp(x._comp), _alloc(x._alloc), _tree(NULL) {
					*this = x;
				};

			~map() {
				delete _tree; // /!\ allocator
				_tree = NULL;
			};


			/****************** MEMBER  FUNCTIONS ******************/
			
			//pb rencontre : ca marchait mais avec insert ca marche pas bien : surement un pb de const iterator

			map<Key, T, Compare, Allocator>& operator=(const map<Key, T, Compare, Allocator>& x) {
				_comp = x._comp;
				_alloc = x.get_allocator();
				if (_tree)
					delete _tree; // /!\ allocator
				_tree = new avl<Key, T>(); // /!\ allocator
				avl<Key, T> *a = x._tree;
				iterator it1 = iterator(x._tree->smallest_node(x._tree->_root), &a);
				iterator it2 = iterator(x._tree->biggest_node(x._tree->_root), &a);
				// insert(it1, it2);
				for (; it1 != it2; it1++)
					insert(ft::make_pair(it1->first, it1->second));
				insert(ft::make_pair(it1->first, it1->second));
				return (*this);
			};
			
			mapped_type& operator[](const key_type& k) {
				return (insert(ft::make_pair(k, mapped_type())).first->second);
			};
			
			mapped_type& at(const key_type& k) {
				iterator it = find(k);
				if (it == end())
					throw (std::out_of_range("map::at"));
				else
					return (it->second);
			};
			
			const mapped_type& at(const key_type& k) const {
				const_iterator it = find(k);
				if (it == end())
					throw (std::out_of_range("map::at"));
				else
					return (it->second);
			};

			allocator_type get_allocator() const {
				allocator_type x;
				return (x);
			};
			
			bool empty() const {
				return(_tree->empty());
			};
			
			size_type size() const {
				return (_tree->size());
			};
			
			size_type max_size() const {
				return (_alloc.max_size());
			};
			
			pair<iterator, bool> insert(const value_type & x) {
				node<Key, T> *new_node = new node<Key, T>(value_type(x)); // /!\ a remplacer par allocator
				bool ok;
				_tree->_root = _tree->insert_node(_tree->_root, new_node, NULL, &ok);
				if (!ok)
					delete new_node;
				pair<iterator, bool> p(find(x.first), ok);
				return (p);
			};

			// pb rencontre : insert ne fonctionne pas bien avec position
			
			// iterator insert(iterator position, const value_type& x) {
			// 	node<Key, T> *new_node = new node<Key, T>(value_type(x)); // /!\ a remplacer par allocator
			// 	(void)position;
			// 	bool ok;
			// 	_tree->_root = _tree->insert_node(_tree->_root, new_node, NULL, &ok);
			// 	if (!ok)
			// 		delete new_node;
			// 	return (find(x.first));
			// };
			
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0) {
				for (InputIterator it = first; it != last; it++)
					insert(it->p);
			};
			
			// pb rencontre : erase ne fonctionne pas bien avec position

			// void erase(iterator position) {
			// 	erase(position->first);
			// };
			
			size_type erase(const key_type& x) {
				if (find(x) == end())
					return (0);
				_tree->_root = _tree->delete_node(_tree->_root, x);
				return (1);
			};
			
			void erase(iterator first, iterator last) {
				for (iterator it = first; it != last; it++)
					erase(it->first);
			};
			
			void swap(map<Key, T, Compare, Allocator>&);
			
			void clear() {
				_tree->clear();
			};
						
			key_compare key_comp() const {
				key_compare x;
				return (x);
			};
			
			value_compare value_comp() const {
				value_compare x(key_comp());
				return (x);
			};

			iterator find(const key_type& x) {
				node<Key, T> * n = _tree->iterative_search(x); // or recursive ?
				if (!n)
					return (end());
				return (iterator(n));
			};
			
			const_iterator find(const key_type& x) const {
				node<Key, T> * n = _tree->iterative_search(x); // or recursive ?
				if (!n)
					return (end());
				return (const_iterator(n));
			};
			
			size_type count(const key_type& x) const {
				if (!(_tree->iterative_search(x)))
					return (0);
				return (1);
			};
			
			// iterator lower_bound(const key_type& x);
			
			// const_iterator lower_bound(const key_type& x) const;
			
			// iterator upper_bound(const key_type& x);
			
			// const_iterator upper_bound(const key_type& x) const;
			
			// pair<iterator,iterator>
			// equal_range(const key_type& x);
			
			// pair<const_iterator,const_iterator>
			// equal_range(const key_type& x) const;


			/********************** ITERATORS **********************/

			iterator begin() {
				return (iterator(_tree->smallest_node(_tree->_root), &_tree));
			};

			const_iterator begin() const {
				return (const_iterator(_tree->smallest_node(_tree->_root), &_tree));
			};

			iterator end() {
				if (!(_tree->_root))
					return (iterator(_tree->biggest_node(_tree->_root), &_tree));
				return (iterator(_tree->biggest_node(_tree->_root)->right, &_tree));
			};

			const_iterator end() const {
				if (!(_tree->_root))
					return (iterator(_tree->biggest_node(_tree->_root), &_tree));
				return (const_iterator(_tree->biggest_node(_tree->_root)->right, &_tree));
			};

			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			};

			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			};
			
		};
	

			/**************** NON MEMBER  FUNCTIONS ****************/

			template <class Key, class T, class Compare, class Allocator>
			bool operator==(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator< (const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator!=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator> (const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator>=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator<=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y);

			template <class Key, class T, class Compare, class Allocator>
			void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y);

}

#endif