#ifndef MAP_HPP
# define MAP_HPP

#include <string>
#include "avl.hpp"
#include "utils.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > // /!\ ft::pair au lieu de stdf
	class map {

		public:

			typedef Key	 									key_type;
			typedef T	 									mapped_type;
			typedef std::pair<const Key, T>					value_type;// /!\ pareil
			typedef Compare	 								key_compare;
			typedef Allocator	 							allocator_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			// typedef implementation defined					iterator;
			// typedef implementation defined					const_iterator;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			// typedef std::reverse_iterator<iterator>			reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;


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

			avl<Key, T>		_tree;
			key_compare		_comp;
			allocator_type	_alloc;


		public :

			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
				: _tree(), _comp(comp), _alloc(alloc) {};

			// template <class InputIterator>
			// map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());

			map(const map<Key, T, Compare, Allocator>& x)
				: _tree(x._tree), _comp(x._comp), _alloc(x._alloc) {};

			~map();


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
			
			size_type max_size() const;
			
			
			// pair<iterator, bool> insert(const value_type& x);
			
			// iterator insert(iterator position, const value_type& x);
			
			// template <class InputIterator>
			// void insert(InputIterator first, InputIterator last);
			
			// void erase(iterator position);
			
			size_type erase(const key_type& x);
			
			// void erase(iterator first, iterator last);
			
			void swap(map<Key,T,Compare,Allocator>&);
			
			void clear();
			
			key_compare key_comp() const;
			
			value_compare value_comp() const;

			// iterator find(const key_type& x);
			
			// const_iterator find(const key_type& x) const;
			
			size_type count(const key_type& x) const;
			
			// iterator lower_bound(const key_type& x);
			
			// const_iterator lower_bound(const key_type& x) const;
			
			// iterator upper_bound(const key_type& x);
			
			// const_iterator upper_bound(const key_type& x) const;
			
			// pair<iterator,iterator>
			// equal_range(const key_type& x);
			
			// pair<const_iterator,const_iterator>
			// equal_range(const key_type& x) const;


			/********************** ITERATORS **********************
			
			
			iterator begin();

			const_iterator begin() const;

			iterator end();

			const_iterator end() const;

			reverse_iterator rbegin();

			const_reverse_iterator rbegin() const;

			reverse_iterator rend();

			const_reverse_iterator rend() const;
			*/
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