#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include "avl.hpp"

namespace ft
{
	template <class Key, class T>
	class node;

	template <class Key, class T>
	class avl;
}

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

			friend bool operator==(const ft::v_iterator<Iterator> & lhs, const ft::v_iterator<Iterator> & rhs) {
				return (lhs.base() == rhs.base());
			};
	
			friend bool operator!=(const ft::v_iterator<Iterator> & lhs, const ft::v_iterator<Iterator> & rhs) {
				return (!(lhs == rhs));
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

			friend v_iterator<Iterator> operator+(difference_type n, const ft::v_iterator<Iterator> & it) {
				return (v_iterator(it.base() + n));
			};
			
			friend difference_type operator-(const ft::v_iterator<Iterator> & lhs, const ft::v_iterator<Iterator> & rhs) {
				return (lhs.base() - rhs.base());
			};	
		};


		/**************** NON MEMBER  FUNCTIONS ****************/

		template <class IteratorL, class IteratorR>
		bool operator==(const ft::v_iterator<IteratorL> & lhs, const ft::v_iterator<IteratorR> & rhs) {
			return (lhs.base() == rhs.base());
		};

		template <class IteratorL, class IteratorR>
		bool operator!=(const ft::v_iterator<IteratorL> & lhs, const ft::v_iterator<IteratorR> & rhs) {
			return (!(lhs == rhs));
		};

		template <class IteratorL, class IteratorR>
		bool operator<(const ft::v_iterator<IteratorL> & lhs, const ft::v_iterator<IteratorR> & rhs) {
			return (lhs.base() < rhs.base());
		};

		template <class IteratorL, class IteratorR>
		bool operator<=(const ft::v_iterator<IteratorL> & lhs, const ft::v_iterator<IteratorR> & rhs) {
			return (lhs.base() <= rhs.base());
		};

		template <class IteratorL, class IteratorR>
		bool operator>(const ft::v_iterator<IteratorL> & lhs, const ft::v_iterator<IteratorR> & rhs) {
			return (lhs.base() > rhs.base());
		};

		template <class IteratorL, class IteratorR>
		bool operator>=(const ft::v_iterator<IteratorL> & lhs, const ft::v_iterator<IteratorR> & rhs) {
			return (lhs.base() >= rhs.base());
		};
			
		template <class IteratorL, class IteratorR>
		typename ft::v_iterator<IteratorL>::difference_type operator-(const ft::v_iterator<IteratorL> & lhs, const ft::v_iterator<IteratorR> & rhs) {
			return (lhs.base() - rhs.base());
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
			typedef ft::node<const Key, T>*											link_type;
	

		protected :

			typedef typename std::allocator<ft::node<const Key, T> >	allocator;
			typedef typename std::allocator<ft::avl<Key, T> > 			avl_allocator;

			iterator_type		current;
			ft::avl<Key, T>		*tree;
			allocator			node_alloc;
			avl_allocator		avl_alloc;


		public :

			/******************** CONSTRUCTORS *********************/

			m_iterator() : current(NULL), tree(NULL), node_alloc(), avl_alloc() {};

			explicit m_iterator(iterator_type x) : current(iterator_type(x)), tree(NULL), node_alloc(), avl_alloc() {};
 
			template <class Iter, class K, class U>
  			m_iterator(const m_iterator<Iter, K, U> & other) : current(other.base()), tree(NULL), node_alloc(), avl_alloc() {
				*this = other;
			};

			m_iterator(const iterator_type p, ft::avl<Key, T> *const* t) : current(iterator_type(p)), tree(*t), node_alloc(), avl_alloc() {};


			/****************** MEMBER  FUNCTIONS ******************/

			template <class Iter, class K, class U>
			m_iterator & operator=(const m_iterator<Iter, K, U> & other) {
				current = other.base();
				tree = other.get_tree();
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

			m_iterator & operator++() {
 				iterator_type p;
				
 				if (!current)
				{
					current = tree->_root;
					if (!current)
						throw (std::exception());
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
			};

			m_iterator & operator--() {
				iterator_type p;

				if (!current)
 				{
					current = tree->_root;
					if (!current)
						throw (std::exception());
					while (current->right)
						current = current->right;
				}
				else if (current->left)
				{
					current = current->left;
					while (current->right)
						current = current->right;
				}
				else
				{
					p = current->parent;
					while (p && current == p->left)
					{
						current = p;
						p = p->parent;
					}
					current = p;
				}
				return (*this);
			};

			m_iterator operator++(int) {
				m_iterator tmp = *this;
				operator++();
				return (tmp);
			};

			m_iterator operator--(int) {
				m_iterator tmp = *this;
				operator--();
				return (tmp);
			};

			ft::avl<Key, T>* get_tree() const {
				return (this->tree);
			};

			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const m_iterator<Iterator, Key, T> & lhs, const m_iterator<Iterator, Key, T> & rhs) {
				return ((lhs.current == rhs.current));
			};
	
			friend bool operator!=(const m_iterator<Iterator, Key, T> & lhs, const m_iterator<Iterator, Key, T> & rhs) {
				return (!(lhs == rhs));
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
		
	template <class Iterator, class Key, class T>
	class const_m_iterator
	{

		public :

			typedef Iterator													iterator_type;
			typedef typename ft::m_iterator<Iterator, Key, T>					m_it;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef ft::node<const Key, T>										type;
			typedef const type													const_type;
			typedef const type*													pointer;
			typedef const type&													reference;

		protected :

			typedef typename std::allocator<ft::node<const Key, T> >	allocator;
			typedef typename std::allocator<ft::avl<Key, T> > 			avl_allocator;

			iterator_type		current;
			ft::avl<Key, T>		*tree;
			allocator			node_alloc;
			avl_allocator		avl_alloc;


		public :

			/******************** CONSTRUCTORS *********************/

			const_m_iterator() : current(NULL), tree(NULL), node_alloc(), avl_alloc() {};

			explicit const_m_iterator(iterator_type x) : current(iterator_type(x)), tree(NULL), node_alloc(), avl_alloc() {};

			const_m_iterator(const m_it & x) : current(x.base()), tree(NULL), node_alloc(), avl_alloc() {};
 
			template <class Iter, class K, class U>
  			const_m_iterator(const const_m_iterator<Iter, K, U> & other) : current(other.base()), tree(NULL), node_alloc(), avl_alloc() {
				*this = other;
			};

			const_m_iterator(const iterator_type p, ft::avl<Key, T> *const* t) : current(iterator_type(p)), tree(*t), node_alloc(), avl_alloc() {};


			/****************** MEMBER  FUNCTIONS ******************/
		
			operator m_it() const {
				return (m_it(const_cast<typename m_it::iterator_type>(current), &tree));
	  		};

			template <class Iter, class K, class U>
			const_m_iterator & operator=(const const_m_iterator<Iter, K, U> & other) {
				current = other.base();
				tree = other.get_tree();
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

			const_m_iterator & operator++() {
 				iterator_type p;
				
 				if (!current)
				{
					current = tree->_root;
					if (!current)
						throw (std::exception());
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
			};

			const_m_iterator & operator--() {
				iterator_type p;

				if (!current)
 				{
					current = tree->_root;
					if (!current)
						throw (std::exception());
					while (current->right)
						current = current->right;
				}
				else if (current->left)
				{
					current = current->left;
					while (current->right)
						current = current->right;
				}
				else
				{
					p = current->parent;
					while (p && current == p->left)
					{
						current = p;
						p = p->parent;
					}
					current = p;
				}
				return (*this);
			};

			const_m_iterator operator++(int) {
				const_m_iterator tmp = *this;
				operator++();
				return (tmp);
			};

			const_m_iterator operator--(int) {
				const_m_iterator tmp = *this;
				operator--();
				return (tmp);
			};

			ft::avl<Key, T>* get_tree() const {
				return (this->tree);
			};

			/**************** NON MEMBER  FUNCTIONS ****************/

			friend bool operator==(const const_m_iterator<Iterator, Key, T> & lhs, const const_m_iterator<Iterator, Key, T> & rhs) {
				return ((lhs.current == rhs.current));
			};
	
			friend bool operator!=(const const_m_iterator<Iterator, Key, T> & lhs, const const_m_iterator<Iterator, Key, T> & rhs) {
				return (!(lhs == rhs));
			};
/*
			friend bool operator<(const ft::const_m_iterator<Iterator> & lhs, const ft::const_m_iterator<Iterator> & rhs) {
				return (lhs.base() < rhs.base());
			};

			friend bool operator<=(const ft::const_m_iterator<Iterator> & lhs, const ft::const_m_iterator<Iterator> & rhs) {
				return (lhs.base() <= rhs.base());
			};

			friend bool operator>(const ft::const_m_iterator<Iterator> & lhs, const ft::const_m_iterator<Iterator> & rhs) {
				return (lhs.base() > rhs.base());
			};

			friend bool operator>=(const ft::const_m_iterator<Iterator> & lhs, const ft::const_m_iterator<Iterator> & rhs) {
				return (lhs.base() >= rhs.base());
			};

			friend const_m_iterator<Iterator> operator+(difference_type n, const const_m_iterator<Iterator> & it) {
				return (const_m_iterator(it.base() + n));
			};
			
			friend difference_type operator-(const const_m_iterator<Iterator> & lhs, const const_m_iterator<Iterator> & rhs) {
				return (lhs.base() - rhs.base());
			};*/
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

			friend bool operator==(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (lhs.base() == rhs.base());
			};
	
			friend bool operator!=(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (lhs.base() != rhs.base());
			};

			friend bool operator<(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (rhs.base() < lhs.base());
			};

			friend bool operator<=(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (rhs.base() >= lhs.base());
			};

			friend bool operator>(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (rhs.base() < lhs.base());
			};

			friend bool operator>=(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (rhs.base() <= lhs.base());
			};

			friend ft::reverse_iterator<Iterator> operator+(difference_type n, const ft::reverse_iterator<Iterator> & it) {
				return (ft::reverse_iterator<Iterator>(it.base() - n));
			};
			
			friend difference_type operator-(const ft::reverse_iterator<Iterator> & lhs, const ft::reverse_iterator<Iterator> & rhs) {
				return (rhs.base() - lhs.base());
			};
		};

		/**************** NON MEMBER  FUNCTIONS ****************/

   		template <typename IteratorL, typename IteratorR>
    	bool operator==(const ft::reverse_iterator<IteratorL>& lhs, const ft::reverse_iterator<IteratorR>& rhs) {
			return (lhs.base() == rhs.base());
		};

  		template<typename IteratorL, typename IteratorR>
    	bool operator<(const ft::reverse_iterator<IteratorL>& lhs, const ft::reverse_iterator<IteratorR>& rhs) {
			return (lhs.base() > rhs.base());
		};

  		template<typename IteratorL, typename IteratorR>
    	bool operator!=(const ft::reverse_iterator<IteratorL>& lhs, const ft::reverse_iterator<IteratorR>& rhs) {
			return (lhs.base() != rhs.base());
		};

  		template<typename IteratorL, typename IteratorR>
    	bool operator>(const ft::reverse_iterator<IteratorL>& lhs, const ft::reverse_iterator<IteratorR>& rhs) {
			return (lhs.base() < rhs.base());
		};

  		template<typename IteratorL, typename IteratorR>
    	bool operator<=(const ft::reverse_iterator<IteratorL>& lhs, const ft::reverse_iterator<IteratorR>& rhs) {
			return (lhs.base() >= rhs.base());
		};

  		template<typename IteratorL, typename IteratorR>
    	bool operator>=(const ft::reverse_iterator<IteratorL>& lhs, const ft::reverse_iterator<IteratorR>& rhs) {
			return (lhs.base() <= rhs.base());
		};

  		template<typename IteratorL, typename IteratorR>
    	typename ft::reverse_iterator<IteratorL>::difference_type
		operator-(const ft::reverse_iterator<IteratorL>& lhs, const ft::reverse_iterator<IteratorR>& rhs) {
			return (rhs.base() - lhs.base());
		};

}

#endif