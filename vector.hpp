#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <exception>


namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		private :

			typedef T				value_type;
			typedef Allocator 		allocator_type;
			typedef std::size_t		size_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T&				reference;
			typedef const T&		const_reference;
			typedef T*				pointer;
			typedef T* const		const_pointer;


		protected :

			allocator_type	_alloc;
			T*				_tab;
			size_type		_size;


		public :

			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			explicit vector (const allocator_type & alloc = allocator_type())
				: _tab(NULL), _size(0) {
					(void)alloc;
				};

			explicit vector (size_type n, const value_type & val = value_type(),
							const allocator_type & alloc = allocator_type())
				: _size(n) {
					(void)alloc;
					_tab = _alloc.allocate(n);
					value_type x = val;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_tab[i], x);
				};
/*
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type());
*/
			vector (const vector & x)
				: _tab(NULL) {
					*this = x;
				}

			~vector() {
				this->clear();
				_alloc.deallocate(_tab, _size);
				_tab = NULL;
				_size = 0;
			};
		
			/****************** MEMBER  FUNCTIONS ******************/

			vector & operator=(const vector & other) {
				if (this->_tab)
				{
					this->clear();
					_alloc.deallocate(_tab, _size);
				}
				_size = other._size;
				_tab = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_tab[i], value_type(other[i]));
				return (*this);
			};

			reference operator[] (size_type n) {
				return (_tab[n]);
			};

			const_reference operator[] (size_type n) const {
				return (_tab[n]);
			};
/*
			void assign (size_type n, const value_type& val) {

			};

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last) {

			};
*/
			allocator_type get_allocator() const {
				Allocator x;
				return (x);
			};
			
			reference at (size_type n) {
				if (n >= _size)
					throw (OutOfRange());
				return (_tab[n]);
			};

			const_reference at (size_type n) const {
				if (n >= _size)					
					throw (OutOfRange());
				return (_tab[n]);
			};

			reference front() {
				return (_tab[0]);
			};
			
			const_reference front() const {
				return (_tab[0]);
			};

			reference back() {
				return (_tab[_size - 1]);
			};
			
			const_reference back() const {
				return (_tab[_size - 1]);
			};
			
			T* data() {
				return (_tab);
			};
			
			const T* data() const {
				return (_tab);
			};

			bool empty() const {
				return (_size == 0);
			};

			size_type size() const {
				return (_size);
			};
/*
			size_type max_size() const {

			};

			void reserve (size_type n) {

			};

			size_type capacity() const {
				
			};
*/
			void clear() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_tab[i]);
				// AFTER -> maybe use erase fct with iterators from beginning to end
				_size = 0;
			};
/*
			iterator insert (iterator position, const value_type & val) {

			};

			void insert (iterator position, size_type n, const value_type & val) {

			};

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last) {

			};

			iterator erase (iterator position) {

			};

			iterator erase (iterator first, iterator last) {

			};

			void push_back (const value_type & val) {

			};

			void pop_back() {

			};

			void resize (size_type n, value_type val = value_type()) {

			};

			void swap (vector & x) {

			};
*/

			/********************** ITERATORS **********************/
/*
    		iterator begin() {

			};

			const_iterator begin() const {

			};

			iterator end() {

			};

			const_iterator end() const {
				
			};

			reverse_iterator rbegin() {

			};

			const_reverse_iterator rbegin() const {

			};

			reverse_iterator rend() {

			};

			const_reverse_iterator rend() const {
				
			};

*/
			/**************** NON MEMBER  FUNCTIONS ****************/
/*			
			friend bool operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				if (lhs.size() == rhs.size())
				{
					int size = lhs.size();
					for (int i = 0; i < size; i++)
					{
						if (lhs[i] != rhs[i])
							return (false);
					}
					return (true);
				}
				return (false);
			}

			friend bool operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				if (lhs.size() == rhs.size())
				{
					int size = lhs.size();
					for (int i = 0; i < size; i++)
					{
						if (lhs[i] != rhs[i])
							return (true);
					}
					return (false);
				}
				return (true);
			}

			// friend bool operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
			// 	//
			// }

			// friend bool operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
			// 	//
			// }

			// friend bool operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
			// 	//
			// }

			// friend bool operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
			// 	//
			// }
			
			template <class T, class Alloc>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
*/
			
			/********************* EXCEPTIONS **********************/

			class OutOfRange : public std::exception
			{
				public :
					virtual const char * what(void) const throw() {
						return ("Out of limits");
					};
			};

	};
}


#endif