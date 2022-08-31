#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <string>
// #include <type_traits>
#include "utils.hpp"

namespace ft
{

	template <class Iterator, typename = void>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class Iterator>
	struct iterator_traits<Iterator, typename ft::enable_if<Iterator::difference_type>::type>
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};


	template <class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};


	template <class Iterator>
	class my_iterator
	{

		public :

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
	

		protected :

			iterator_type current;


		public :

			/******************** CONSTRUCTORS *********************/

			my_iterator() : current() {};

			explicit my_iterator(iterator_type x) : current(x) {};

			template <class Iter>
  			my_iterator(const my_iterator<Iter> & other) : current(other.base()) {};


			/****************** MEMBER  FUNCTIONS ******************/

			template <class Iter>
			my_iterator & operator=(const my_iterator<Iter> & other) {
				current = other.base();
				return (*this);
			};

			iterator_type base() const {
				return (current);
			};

			reference operator*() const {
				return (*current);
			};

			reference operator->() const {
				return (current);
			};

			reference operator[](difference_type n) const {
				return (current[n]);
			};

			my_iterator & operator++() {
				++current;
				return (*this);
			}

			my_iterator & operator--() {
				--current;
				return (*this);
			}

			my_iterator operator++(int) {
				my_iterator tmp = *this;
				++current;
				return (tmp);
			}

			my_iterator operator--(int) {
				my_iterator tmp = *this;
				--current;
				return (tmp);
			}

			my_iterator operator+(difference_type n) const {
				return (my_iterator(current + n));
			}

			my_iterator operator-(difference_type n) const {
				return (my_iterator(current - n));
			}

			my_iterator & operator+=(difference_type n) {
				current += n;
				return (*this);
			}

			my_iterator & operator-=(difference_type n) {
				current -= n;
				return (*this);
			}


			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const my_iterator<Iterator> & lhs, const my_iterator<Iterator> & rhs) {
				return (lhs.base() == rhs.base());
			};
	
			friend bool operator!=(const my_iterator<Iterator> & lhs, const my_iterator<Iterator> & rhs) {
				return (lhs.base() != rhs.base());
			};

			friend bool operator<(const ft::my_iterator<Iterator> & lhs, const ft::my_iterator<Iterator> & rhs) {
				return (lhs.base() < rhs.base());
			};

			friend bool operator<=(const ft::my_iterator<Iterator> & lhs, const ft::my_iterator<Iterator> & rhs) {
				return (lhs.base() <= rhs.base());
			};

			friend bool operator>(const ft::my_iterator<Iterator> & lhs, const ft::my_iterator<Iterator> & rhs) {
				return (lhs.base() > rhs.base());
			};

			friend bool operator>=(const ft::my_iterator<Iterator> & lhs, const ft::my_iterator<Iterator> & rhs) {
				return (lhs.base() >= rhs.base());
			};

			friend my_iterator<Iterator> operator+(difference_type n, const my_iterator<Iterator> & it) {
				return (my_iterator(it.base() + n));
			};
			
			friend difference_type operator-(const my_iterator<Iterator> & lhs, const my_iterator<Iterator> & rhs) {
				return (rhs.base() - lhs.base());
			};	
		};


	template <class Iterator>
	class reverse_iterator
	{
		public :

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
	

		protected :

			iterator_type current;


		public :

			/******************** CONSTRUCTORS *********************/

			reverse_iterator() : current() {};

			explicit reverse_iterator(iterator_type x) : current(x) {};

			template <class Iter>
  			reverse_iterator(const reverse_iterator<Iter> & other) : current(other.base()) {};


			/****************** MEMBER  FUNCTIONS ******************/

			template <class Iter>
			reverse_iterator & operator=(const reverse_iterator<Iter> & other) {
				current = other.base();
				return (*this);
			};

			iterator_type base() const {
				return (current);
			};

			reference operator*() const {
				iterator_type tmp = current;
				return (*--tmp);
			};

			pointer operator->() const {
				return (&(operator*()));
			};

			reference operator[](difference_type n) const {  // NEW, A TESTER
				return (*(*this + n));
			};

			reverse_iterator & operator++() {
				--current;
				return (*this);
			}

			reverse_iterator & operator--() {
				++current;
				return (*this);
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				--current;
				return (tmp);
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				++current;
				return (tmp);
			}

			reverse_iterator operator+(difference_type n) const {
				return (reverse_iterator(current - n));
			}

			reverse_iterator operator-(difference_type n) const {
				return (reverse_iterator(current + n));
			}

			reverse_iterator & operator+=(difference_type n) {
				current -= n;
				return (*this);
			}

			reverse_iterator & operator-=(difference_type n) {
				current += n;
				return (*this);
			}

	
			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs) {
				return (lhs.base() == rhs.base());
			};
	
			friend bool operator!=(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs) {
				return (lhs.base() != rhs.base());
			};

			friend bool operator<(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (lhs.base() > rhs.base());
			};

			friend bool operator<=(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (lhs.base() >= rhs.base());
			};

			friend bool operator>(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (lhs.base() < rhs.base());
			};

			friend bool operator>=(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (lhs.base() <= rhs.base());
			};

			friend reverse_iterator<Iterator> operator+(difference_type n, const reverse_iterator<Iterator> & it) {
				return (reverse_iterator(it.base() - n));
			};
			
			friend difference_type operator-(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs) {
				return (rhs.base() - lhs.base());
			};
		};

}

#endif