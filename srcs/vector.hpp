
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <stdexcept>
#include <exception>
#include <math.h>
#include "colors.h"
#include "iterator.hpp"


namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public :

			typedef T												value_type;
			typedef Allocator 										allocator_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef typename ft::my_iterator<pointer>				iterator;
			typedef	typename ft::my_iterator<const_pointer>			const_iterator;
			typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


		private :

			T*				_tab;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;


		public :


			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			explicit vector(const allocator_type & alloc = allocator_type())
				: _tab(NULL), _size(0), _capacity(0) , _alloc(alloc) {};

			explicit vector(size_type n, const value_type & val = value_type(),
						const allocator_type & alloc = allocator_type())
				: _size(n), _capacity(n), _alloc(alloc) {
					_tab = _alloc.allocate(_capacity);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_tab[i], value_type(val));
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0)
				: _tab(NULL), _size(0), _capacity(0), _alloc(alloc) {
					insert(begin(), first, last);
			}

			vector(const vector & x)
				: _size(x.size()), _capacity(x.size()), _alloc(x.get_allocator()) {
					_tab = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_tab[i], value_type(x[i]));
			}

			~vector() {
				clear();
				_alloc.deallocate(_tab, _capacity);
				_tab = NULL;
			};
		

			/****************** MEMBER  FUNCTIONS ******************/

			vector & operator=(const vector & other) {
				if (_size)
				{
					clear();
					_alloc.deallocate(_tab, _capacity);
				}
				_size = other.size();
				_capacity = other.capacity();
				_alloc = other.get_allocator();
				_tab = _alloc.allocate(_capacity);
				assign(other.begin(), other.end());
				return (*this);
			};

			reference operator[](size_type n) {
				return (_tab[n]);
			};

			const_reference operator[](size_type n) const {
				return (_tab[n]);
			};

			void assign(size_type n, const value_type & val) {
				clear();
				if (n > _capacity)
					reserve(n);
				for (size_type i = 0; i < n; i++)
					push_back(value_type(val));
				_size = n;
			};

			template <class InputIterator>
  			void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0) {
				clear();
				size_type n = abs(last - first);
				if (n > _capacity)
					reserve(n);
				InputIterator tmp = first;
				for (; tmp != last; tmp++)
					push_back(*tmp);
			};

			allocator_type get_allocator() const {
				Allocator x;
				return (x);
			};
			
			reference at(size_type n) {
				if (n >= _size)
					throw (std::out_of_range("vector::out of range"));
				return (_tab[n]);
			};

			const_reference at(size_type n) const {
				if (n >= _size)					
					throw (std::out_of_range("vector::out of range"));
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

			size_type max_size() const {
				return (_alloc.max_size());
			};

			void reserve(size_type n) {
				if (n > max_size())
					throw (std::length_error("vector::reserve"));
				if (n > _capacity)
				{
					T* tab = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tab[i], _tab[i]);
					int size = _size;
					clear();
					if (_tab)
						_alloc.deallocate(_tab, _capacity);
					_tab = tab;
					_size = size;
					_capacity = n;
				}
			};

			size_type capacity() const {
				return (_capacity);
			};

			void clear() {
				if (_size)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_tab[i]);
					_size = 0;
				}
			};

			iterator insert(iterator position, const value_type & val) {
				if (position == end())
				{
					push_back(value_type(val));
					return (iterator(end() - 1));
				}

				vector x;
				int a = 0;
				iterator it1, it2;
				for (it1 = begin(); it1 != position; it1++)
				{
					x.push_back(value_type(*it1));
					a++;
				}
				x.push_back(value_type(val));
				for (it2 = it1; it2 != end(); it2++)
					x.push_back(value_type(*it2));
				*this = x;
				return (iterator(_tab + a));
			};

			void insert(iterator position, size_type n, const value_type & val) {
				if (position == end())
				{
					if (n > _size)
						reserve(_size + n);
					for (size_type i = 0; i < n; i++)
						push_back(value_type(val));
					return ;
				}

				vector x;
				iterator it1, it2;
				if (_size + n > _capacity)
					x.reserve(n > _size ? _size + n : _size * 2);
				for (it1 = begin(); it1 != position; it1++)
					x.push_back(value_type(*it1));
				for (size_type i = 0; i < n; i++)
					x.push_back(value_type(val));
				for (iterator it2 = it1; it2 != end(); it2++)
					x.push_back(value_type(*it2));
				*this = x;
			};

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0) {
				size_type n = abs(last - first);
				if (position == end())
				{
					if (n > _size)
						reserve(_size + n);
					for (InputIterator iit = first; iit != last; iit++)
						push_back(value_type(*iit));
					return ;
				}

				vector x;
				iterator it1, it2;
				if (_size + n > _capacity)
					x.reserve(n > _size ? _size + n : _size * 2);
				for (it1 = begin(); it1 != position; it1++)
					x.push_back(value_type(*it1));
				for (InputIterator iit = first; iit != last; iit++)
					x.push_back(value_type(*iit));
				for (iterator it2 = it1; it2 != end(); it2++)
					x.push_back(value_type(*it2));
				*this = x;
			};

			iterator erase(iterator position) {
				if (position == end() - 1)
				{
					pop_back();
					return (end());
				}
				
				vector x;
				int a = 0;
				iterator it1;
				x.reserve(_capacity);
				for (it1 = begin(); it1 != position; it1++)
				{
					x.push_back(value_type(*it1));
					a++;
				}
				for (iterator it2 = ++it1; it2 != end(); it2++)
					x.push_back(value_type(*it2));
				*this = x;
				return (iterator(_tab + a));
			};

			iterator erase(iterator first, iterator last) {
				if (first == last)
					return (last);
				
				vector x;
				int a = 0;
				iterator it1;
				x.reserve(_capacity);
				for (it1 = begin(); it1 != first; it1++)
				{
					x.push_back(value_type(*it1));
					a++;
				}
				for (iterator it2 = last; it2 != end(); it2++)
					x.push_back(value_type(*it2));
				*this = x;
				return (iterator(_tab + a));
			};

			void push_back(const value_type & val) {
				if (_size + 1 > _capacity)
				{
					if (!_capacity)
						_capacity++;
					T* tab = _alloc.allocate(_capacity * 2);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tab[i], value_type(_tab[i]));
					_alloc.construct(&tab[_size], value_type(val));
					size_type size = _size;
					clear();
					_alloc.deallocate(_tab, _capacity);
					_tab = tab;
					_size = size + 1;
					_capacity *= 2;
				}
				else
				{
					_alloc.construct(&_tab[_size], value_type(val));
					_size++;
				}
			};

			void pop_back() {
				_alloc.destroy(&_tab[_size - 1]);
				_size--;
			};

			void resize(size_type n, value_type val = value_type()) {
				if (n < _size)
				{
					size_type i = _size - n;
					for (size_type j = 0; j < i; j++)
						pop_back();
				}
				else if (n > _size)
				{
					if (n > _capacity)
						reserve(n);
					size_type i = n - _size;
					for (size_type j = 0; j < i; j++)
						push_back(val);
				}
			};

			void swap(vector & x) {
				T* tmp_tab = x._tab;
				size_type tmp_size = x._size;
				size_type tmp_capacity = x._capacity;

				x._tab = this->_tab;
				x._size = this->_size;
				x._capacity = this->_capacity;

				this->_tab = tmp_tab;
				this->_size = tmp_size;
				this->_capacity = tmp_capacity;
			};


			/********************** ITERATORS **********************/

  			iterator begin() {
				return (iterator(_tab));
			};

			iterator end() {
				return (iterator(_tab + _size));
			};

			const_iterator begin() const {
				return (const_iterator(_tab));
			};

			const_iterator end() const {
				return (const_iterator(_tab + _size));
			};

			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			};

			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			};

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			};


			/**************** NON MEMBER  FUNCTIONS ****************/
		
			friend bool operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			friend bool operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				return (!(lhs == rhs));
			}

			friend bool operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

			friend bool operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				return (!(rhs < lhs));
			}

			friend bool operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				return (rhs < lhs);
			}

			friend bool operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs) {
				return (!(lhs < rhs));
			}

	};
}

#endif