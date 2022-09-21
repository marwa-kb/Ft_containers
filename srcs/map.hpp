#ifndef MAP_HPP
# define MAP_HPP

#include <string>
#include "avl.hpp"
#include "utils.hpp"
#include "iterators.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > // /!\ ft::pair au lieu de stdf
	class map
	{

		public:

			typedef Key	 												key_type;
			typedef T	 												mapped_type;
			typedef Compare	 											key_compare;
			typedef std::pair<const Key, T>								value_type;// /!\ pareil
			typedef Allocator	 										allocator_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef value_type&											reference;
			typedef const value_type&									const_reference;
			typedef value_type*											pointer;
			typedef const value_type*									const_pointer;
			typedef typename ft::m_iterator<node<Key, T> >				iterator;
			typedef typename ft::m_iterator<const node<Key, T> >		const_iterator;
			typedef typename ft::m_reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::m_reverse_iterator<const_iterator>		const_reverse_iterator;


			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {};
			
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool operator()(const value_type& x, const value_type& y) const {
						return (comp(x.first, y.first));
					};
			};
			

		private :

			avl<Key, T>	_tree;
			key_compare		_comp;
			allocator_type	_alloc;


		public :

			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
				: _tree(), _comp(comp), _alloc(alloc) {};

			// template <class InputIterator>
			// map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());

			// map(const map<Key, T, Compare, Allocator>& x)
				// : _tree(x._tree), _comp(x._comp), _alloc(x._alloc) {};

			~map() {};


			/****************** MEMBER  FUNCTIONS ******************/
			
			map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x);
			
			T& operator[](const key_type& x);

			allocator_type get_allocator() const {
				allocator_type x;
				return (x);
			};
			
			bool empty() const {
				return(_tree.empty());
			};
			
			size_type size() const {
				return (_tree.size());
			};
			
			size_type max_size() const {
				return (_alloc.max_size());
			};
			
			// pair<iterator, bool> insert(const value_type& x) {
			// 	node<Key, T> * new_node = new node<Key, T>(x); // /!\ a remplacer par allocator
			// 	bool ok = true;
			// 	return (pair<iterator, bool>(_tree.insert_node(_tree._root, new_node, &ok), ok));
			// };
			
			// iterator insert(iterator position, const value_type& x);
			
			// template <class InputIterator>
			// void insert(InputIterator first, InputIterator last);
			
			// void erase(iterator position);
			
			size_type erase(const key_type& x) {
				if (!(_tree.delete_node(_tree._root, x)))
					return (0);
				return (1);
			};
			
			// void erase(iterator first, iterator last);
			
			void swap(map<Key,T,Compare,Allocator>&);
			
			void clear();
			
			key_compare key_comp() const;
			
			value_compare value_comp() const;

			// iterator find(const key_type& x);
			
			// const_iterator find(const key_type& x) const;
			
			size_type count(const key_type& x) const {
				if (!(_tree.iterative_search(x)))
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
				return (iterator(_tree.smallest_node(_tree._root), &_tree));
			};

			const_iterator begin() const {
				return (const_iterator(_tree.smallest_node(_tree._root), &_tree));
			};

			iterator end() {
				return (iterator(NULL, &_tree));
			};

			const_iterator end() const{
				return (const_iterator(NULL, &_tree));
			};

			reverse_iterator rbegin();

			const_reverse_iterator rbegin() const;

			reverse_iterator rend();

			const_reverse_iterator rend() const;
			
		};
	

			/**************** NON MEMBER  FUNCTIONS ****************/

	
			template <class Key, class T, class Compare, class Allocator>
			bool operator==(const map<Key,T,Compare,Allocator>& x,
			const map<Key,T,Compare,Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator< (const map<Key,T,Compare,Allocator>& x,
			const map<Key,T,Compare,Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator!=(const map<Key,T,Compare,Allocator>& x,
			const map<Key,T,Compare,Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator> (const map<Key,T,Compare,Allocator>& x,
			const map<Key,T,Compare,Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator>=(const map<Key,T,Compare,Allocator>& x,
			const map<Key,T,Compare,Allocator>& y);
			
			template <class Key, class T, class Compare, class Allocator>
			bool operator<=(const map<Key,T,Compare,Allocator>& x,
			const map<Key,T,Compare,Allocator>& y);
			// specialized algorithms:
			
			template <class Key, class T, class Compare, class Allocator>
			void swap(map<Key,T,Compare,Allocator>& x,
			map<Key,T,Compare,Allocator>& y);

}

#endif