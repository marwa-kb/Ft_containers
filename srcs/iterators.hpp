#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include <string>
#include "utils.hpp"
#include "avl.hpp"

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
	class v_iterator
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

			v_iterator() : current(Iterator()) {};

			explicit v_iterator(iterator_type x) : current(x) {};

			template <class Iter>
  			v_iterator(const v_iterator<Iter> & other) : current(other.base()) {};


			/****************** MEMBER  FUNCTIONS ******************/

			template <class Iter>
			v_iterator & operator=(const v_iterator<Iter> & other) {
				current = other.base();
				return (*this);
			};

			iterator_type base() const {
				return (current);
			};

			reference operator*() const {
				return (*current);
			};

			pointer operator->() const {
				return (current);
			};

			reference operator[](difference_type n) const {
				return (current[n]);
			};

			v_iterator & operator++() {
				++current;
				return (*this);
			}

			v_iterator & operator--() {
				--current;
				return (*this);
			}

			v_iterator operator++(int) {
				v_iterator tmp = *this;
				++current;
				return (tmp);
			}

			v_iterator operator--(int) {
				v_iterator tmp = *this;
				--current;
				return (tmp);
			}

			v_iterator operator+(difference_type n) const {
				return (v_iterator(current + n));
			}

			v_iterator operator-(difference_type n) const {
				return (v_iterator(current - n));
			}

			v_iterator & operator+=(difference_type n) {
				current += n;
				return (*this);
			}

			v_iterator & operator-=(difference_type n) {
				current -= n;
				return (*this);
			}


			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const v_iterator<Iterator> & lhs, const v_iterator<Iterator> & rhs) {
				return (lhs.base() == rhs.base());
			};
	
			friend bool operator!=(const v_iterator<Iterator> & lhs, const v_iterator<Iterator> & rhs) {
				return (lhs.base() != rhs.base());
			};

			friend bool operator<(const ft::v_iterator<Iterator> & lhs, const ft::v_iterator<Iterator> & rhs) {
				return (lhs.base() < rhs.base());
			};

			friend bool operator<=(const ft::v_iterator<Iterator> & lhs, const ft::v_iterator<Iterator> & rhs) {
				return (lhs.base() <= rhs.base());
			};

			friend bool operator>(const ft::v_iterator<Iterator> & lhs, const ft::v_iterator<Iterator> & rhs) {
				return (lhs.base() > rhs.base());
			};

			friend bool operator>=(const ft::v_iterator<Iterator> & lhs, const ft::v_iterator<Iterator> & rhs) {
				return (lhs.base() >= rhs.base());
			};

			friend v_iterator<Iterator> operator+(difference_type n, const v_iterator<Iterator> & it) {
				return (v_iterator(it.base() + n));
			};
			
			friend difference_type operator-(const v_iterator<Iterator> & lhs, const v_iterator<Iterator> & rhs) {
				return (lhs.base() - rhs.base());
			};	
		};


	template <class Iterator>
	class v_reverse_iterator
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

			v_reverse_iterator() : current() {};

			explicit v_reverse_iterator(iterator_type x) : current(x) {};

			template <class Iter>
  			v_reverse_iterator(const v_reverse_iterator<Iter> & other) : current(other.base()) {};


			/****************** MEMBER  FUNCTIONS ******************/

			template <class Iter>
			v_reverse_iterator & operator=(const v_reverse_iterator<Iter> & other) {
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

			v_reverse_iterator & operator++() {
				--current;
				return (*this);
			}

			v_reverse_iterator & operator--() {
				++current;
				return (*this);
			}

			v_reverse_iterator operator++(int) {
				v_reverse_iterator tmp = *this;
				--current;
				return (tmp);
			}

			v_reverse_iterator operator--(int) {
				v_reverse_iterator tmp = *this;
				++current;
				return (tmp);
			}

			v_reverse_iterator operator+(difference_type n) const {
				return (v_reverse_iterator(current - n));
			}

			v_reverse_iterator operator-(difference_type n) const {
				return (v_reverse_iterator(current + n));
			}

			v_reverse_iterator & operator+=(difference_type n) {
				current -= n;
				return (*this);
			}

			v_reverse_iterator & operator-=(difference_type n) {
				current += n;
				return (*this);
			}

	
			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const v_reverse_iterator<Iterator> & lhs, const v_reverse_iterator<Iterator> & rhs) {
				return (lhs.base() == rhs.base());
			};
	
			friend bool operator!=(const v_reverse_iterator<Iterator> & lhs, const v_reverse_iterator<Iterator> & rhs) {
				return (lhs.base() != rhs.base());
			};

			friend bool operator<(const ft::v_reverse_iterator<Iterator> & lhs, const ft::v_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() < lhs.base());
			};

			friend bool operator<=(const ft::v_reverse_iterator<Iterator> & lhs, const ft::v_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() >= lhs.base());
			};

			friend bool operator>(const ft::v_reverse_iterator<Iterator> & lhs, const ft::v_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() < lhs.base());
			};

			friend bool operator>=(const ft::v_reverse_iterator<Iterator> & lhs, const ft::v_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() <= lhs.base());
			};

			friend v_reverse_iterator<Iterator> operator+(difference_type n, const v_reverse_iterator<Iterator> & it) {
				return (v_reverse_iterator(it.base() - n));
			};
			
			friend difference_type operator-(const v_reverse_iterator<Iterator> & lhs, const v_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() - lhs.base());
			};
		};


	template <class Iterator, class Key, class T>
	class m_iterator
	{

		public :

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
	

		protected :

			iterator_type	current;
			avl<Key, T>		*tree;


		public :

			/******************** CONSTRUCTORS *********************/

			m_iterator() : current(iterator_type()) {};

			explicit m_iterator(iterator_type x) : current(iterator_type(x)) {};

			// template <class Iter>
  			// m_iterator(const m_iterator<Iter> & other) : current(other.base()) {};

			m_iterator(const iterator_type p, avl<Key, T> *t) : current(p), tree(t) {};


			/****************** MEMBER  FUNCTIONS ******************/

			// template <class Iter>
			// m_iterator & operator=(const m_iterator<Iter> & other) {
				// current = other.base();
				// return (*this);
			// };

			iterator_type base() const {
				return (current);
			};

			reference operator*() const {
				return (*current);
			};

			pointer operator->() const {
				return (current);
			};

			reference operator[](difference_type n) const {	// ?
				return (current[n]);
			};

			m_iterator & operator++()
			{
 				iterator_type p;

 				if (!current)
 				{
 					current = tree->_root;
 					if (!current)
 						return (m_iterator(NULL));
 					while (current->left)
 						current = current->left;
 				}
 				else if (current->right)
 				{
 					current = current->right;
					while (current->left)
 						current = current->left;	
 				}
 				else
 				{
 					p = current->parent;
 					while (p && current == p->right)
 					{
 						current = p;
 						p = p->parent;
 					}
 					current = p;
 				}
 				return (*this);
			}

			m_iterator & operator--() {
				--current;
				return (*this);
			}

			m_iterator operator++(int) {
				m_iterator tmp = *this;
				++current;
				return (tmp);
			}

			m_iterator operator--(int) {
				m_iterator tmp = *this;
				--current;
				return (tmp);
			}

			m_iterator operator+(difference_type n) const {
				return (m_iterator(current + n));
			}

			m_iterator operator-(difference_type n) const {
				return (m_iterator(current - n));
			}

			m_iterator & operator+=(difference_type n) {
				current += n;
				return (*this);
			}

			m_iterator & operator-=(difference_type n) {
				current -= n;
				return (*this);
			}


			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const m_iterator<Iterator, Key, T> & lhs, const m_iterator<Iterator, Key, T> & rhs) {
        		return ((lhs.tree == rhs.tree) && (lhs.current == rhs.current));
			};
	
			friend bool operator!=(const m_iterator<Iterator, Key, T> & lhs, const m_iterator<Iterator, Key, T> & rhs) {
        		return ((lhs.tree != rhs.tree) && (lhs.current != rhs.current));
			};
/*
			friend bool operator<(const ft::m_iterator<Iterator> & lhs, const ft::m_iterator<Iterator> & rhs) {
				return (lhs.base() < rhs.base());
			};

			friend bool operator<=(const ft::m_iterator<Iterator> & lhs, const ft::m_iterator<Iterator> & rhs) {
				return (lhs.base() <= rhs.base());
			};

			friend bool operator>(const ft::m_iterator<Iterator> & lhs, const ft::m_iterator<Iterator> & rhs) {
				return (lhs.base() > rhs.base());
			};

			friend bool operator>=(const ft::m_iterator<Iterator> & lhs, const ft::m_iterator<Iterator> & rhs) {
				return (lhs.base() >= rhs.base());
			};

			friend m_iterator<Iterator> operator+(difference_type n, const m_iterator<Iterator> & it) {
				return (m_iterator(it.base() + n));
			};
			
			friend difference_type operator-(const m_iterator<Iterator> & lhs, const m_iterator<Iterator> & rhs) {
				return (lhs.base() - rhs.base());
			};*/
		};


	template <class Iterator>
	class m_reverse_iterator
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

			m_reverse_iterator() : current() {};

			explicit m_reverse_iterator(iterator_type x) : current(x) {};

			template <class Iter>
  			m_reverse_iterator(const m_reverse_iterator<Iter> & other) : current(other.base()) {};


			/****************** MEMBER  FUNCTIONS ******************/

			template <class Iter>
			m_reverse_iterator & operator=(const m_reverse_iterator<Iter> & other) {
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

			m_reverse_iterator & operator++() {
				--current;
				return (*this);
			}

			m_reverse_iterator & operator--() {
				++current;
				return (*this);
			}

			m_reverse_iterator operator++(int) {
				m_reverse_iterator tmp = *this;
				--current;
				return (tmp);
			}

			m_reverse_iterator operator--(int) {
				m_reverse_iterator tmp = *this;
				++current;
				return (tmp);
			}

			m_reverse_iterator operator+(difference_type n) const {
				return (m_reverse_iterator(current - n));
			}

			m_reverse_iterator operator-(difference_type n) const {
				return (m_reverse_iterator(current + n));
			}

			m_reverse_iterator & operator+=(difference_type n) {
				current -= n;
				return (*this);
			}

			m_reverse_iterator & operator-=(difference_type n) {
				current += n;
				return (*this);
			}

	
			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const m_reverse_iterator<Iterator> & lhs, const m_reverse_iterator<Iterator> & rhs) {
				return (lhs.base() == rhs.base());
			};
	
			friend bool operator!=(const m_reverse_iterator<Iterator> & lhs, const m_reverse_iterator<Iterator> & rhs) {
				return (lhs.base() != rhs.base());
			};

			friend bool operator<(const ft::m_reverse_iterator<Iterator> & lhs, const ft::m_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() < lhs.base());
			};

			friend bool operator<=(const ft::m_reverse_iterator<Iterator> & lhs, const ft::m_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() >= lhs.base());
			};

			friend bool operator>(const ft::m_reverse_iterator<Iterator> & lhs, const ft::m_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() < lhs.base());
			};

			friend bool operator>=(const ft::m_reverse_iterator<Iterator> & lhs, const ft::m_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() <= lhs.base());
			};

			friend m_reverse_iterator<Iterator> operator+(difference_type n, const m_reverse_iterator<Iterator> & it) {
				return (m_reverse_iterator(it.base() - n));
			};
			
			friend difference_type operator-(const m_reverse_iterator<Iterator> & lhs, const m_reverse_iterator<Iterator> & rhs) {
				return (rhs.base() - lhs.base());
			};
		};

}

#endif