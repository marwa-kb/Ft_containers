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

			typedef typename std::allocator<node<const Key, T> >	allocator;
			typedef typename std::allocator<avl<Key, T> > 			avl_allocator;

			iterator_type		current;
			avl<Key, T>			*tree;
			allocator			node_alloc;
			avl_allocator		avl_alloc;

		
			avl<Key, T> *create_avl() {
				avl<Key, T> *tree = avl_alloc.allocate(1);
				avl_alloc.construct(&tree[0], avl<Key, T>());
				return (tree);
			};

			void destroy_avl() {
				avl_alloc.destroy(&tree[0]);
				avl_alloc.deallocate(tree, 1);
				tree = NULL;
			};

			node<Key, T> *create_node(const ft::pair<const Key, T> & x) {
				node<Key, T> * n = node_alloc.allocate(1);
				// std::cout << BY << "In insert(it, x),  it->first = " << x.first << " et it->second = " << x.second << NC << std::endl; 
				node_alloc.construct(&n[0], x);
				// std::cout << BR << "In insert(it, x),  it->first = " << x.first << " et it->second = " << x.second << NC << std::endl; 

				return (n);
			};

			void destroy_node(node<Key, T> * n) {
				node_alloc.destroy(&n[0]);
				node_alloc.deallocate(n, 1);
				n = NULL;
			};


		public :

			/******************** CONSTRUCTORS *********************/

			m_iterator() : current(NULL) {};

			explicit m_iterator(iterator_type x) : current(iterator_type(x)) {};
 
			template <class Iter, class K, class U>
  			m_iterator(const m_iterator<Iter, K, U> & other) : current(other.base()) {
				// *this = other;
			};

			m_iterator(const iterator_type p, avl<Key, T> *const* t) : current(iterator_type(p)), tree(*t) {};

			// m_iterator(const iterator_type p, const avl<Key, T> **t) : current(iterator_type(p)), tree(*t) {};


			/****************** MEMBER  FUNCTIONS ******************/

			// operator m_iterator<Iterator const, Key, T>() const {
			// 	return(m_iterator<Iterator const, Key, T>(current, tree));
			// };

			template <class Iter, class K, class U>
			m_iterator & operator=(const m_iterator<Iter, K, U> & other) {
				std::cout << BP << "ici dans copy assignment operator)" << NC << std::endl;

				current = other.base();
				if (tree)
					destroy_avl();
				m_iterator<node<K, U>*, K, U> it1(other->tree->smallest_node(), &other->tree);
				m_iterator<node<K, U>*, K, U> it2(other->tree->biggest_node(), &other->tree);
				for (; it1 != it2; it1++)
				{
					node<K, U> * n = create_node(ft::make_pair<K, U>(it1->first, it1->second));
					tree->insert_node(n, tree->_root, NULL, NULL);
				}
				node<K, U> * n = create_node(ft::make_pair<K, U>(it1->first, it1->second));
				tree->insert_node(n, tree->_root, NULL, NULL);
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

			friend reverse_iterator<Iterator> operator+(difference_type n, const reverse_iterator<Iterator> & it) {
				return (reverse_iterator(it.base() - n));
			};
			
			friend difference_type operator-(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs) {
				return (rhs.base() - lhs.base());
			};
		};

}

#endif