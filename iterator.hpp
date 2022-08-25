#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <string>

namespace ft
{

	template <class Iterator>
	struct iterator_traits
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

			reverse_iterator() {
				std::cout << BO << "BIEN DANS REVERSE ITERATOR" << NC << std::endl;
			};

			explicit reverse_iterator(iterator_type x) : current(x) {
				std::cout << BO << "BIEN DANS REVERSE ITERATOR" << NC << std::endl;
			};

			template <class Iter>
  			reverse_iterator(const reverse_iterator<Iter> & other) : current(other.current) {
				std::cout << BO << "BIEN DANS REVERSE ITERATOR" << NC << std::endl;
			};


			/****************** MEMBER  FUNCTIONS ******************/

			template <class Iter>
			reverse_iterator & operator=(const reverse_iterator<Iter> & other) {
				current = other.base();
			};

			iterator_type base() const {
				return (current);
			};

			reference operator*() const {
				std::cout << BP << "ICIIII" << NC << std::endl;
				iterator_type tmp = current;
				return (*--tmp);
			};
/*
			reference operator-> const {

			};

			reference operator[] const {

			};
*/
			reverse_iterator & operator++() {
				std::cout << BP << "ICIIII" << NC << std::endl;
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
/*
			reverse_iterator operator+(difference_type n) const {

			}

			reverse_iterator operator-(difference_type n) const {

			}

			reverse_iterator & operator+=(difference_type n) {

			}

			reverse_iterator & operator-=(difference_type n) {

			}

	*/		
			/**************** NON MEMBER  FUNCTIONS ****************/
/*
			friend bool operator==(const std::reverse_iterator<Iterator1> & lhs, const std::reverse_iterator<Iterator2> & rhs) {

			};
	
			friend bool operator!=(const std::reverse_iterator<Iterator1> & lhs, const std::reverse_iterator<Iterator2> & rhs) {

			};

			friend bool operator<(const std::reverse_iterator<Iterator1> & lhs, const std::reverse_iterator<Iterator2> & rhs) {

			};

			friend bool operator<=(const std::reverse_iterator<Iterator1> & lhs, const std::reverse_iterator<Iterator2> & rhs) {

			};

			friend bool operator>(const std::reverse_iterator<Iterator1> & lhs, const std::reverse_iterator<Iterator2> & rhs) {

			};

			friend bool operator>=(const std::reverse_iterator<Iterator1> & lhs, const std::reverse_iterator<Iterator2> & rhs) {

			};

			friend reverse_iterator<Iterator> operator+(difference_type n, const reverse_iterator<Iterator> & it) {

			};
			
			friend difference_type operator-(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs) {

			};	
	*/};

}

#endif