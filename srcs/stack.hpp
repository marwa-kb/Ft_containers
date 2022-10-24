#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <typename T, class Container = ft::vector<T> >
	class stack
	{

		public:

			typedef Container						container_type;
			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;


		protected :

			Container c;


		public :

			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			explicit stack(const Container & cont = Container()) : c(cont) {};

			~stack() {};


			/****************** MEMBER  FUNCTIONS ******************/
			
			stack & operator=(const stack & other) {
				c = other.c;
				return (*this);
			};

			value_type & top() {
				return (c.back());
			};

			const value_type & top() const {
				return (c.back());
			};

			bool empty() const {
				return (c.empty());
			};

			size_type size() const {
				return (c.size());
			};

			void push(const value_type & value) {
				c.push_back(value);
			};

			void pop() {
				c.pop_back();
			};


			/**************** NON MEMBER  FUNCTIONS ****************/
			
			friend bool operator==(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
				return (lhs.c == rhs.c);
			}

			friend bool operator!=(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
				return (lhs.c != rhs.c);
			}

			friend bool operator<(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
				return (lhs.c < rhs.c);
			}

			friend bool operator<=(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
				return (lhs.c <= rhs.c);
			}

			friend bool operator>(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
				return (lhs.c > rhs.c);
			}

			friend bool operator>=(const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) {
				return (lhs.c >= rhs.c);
			}
	};
}

#endif