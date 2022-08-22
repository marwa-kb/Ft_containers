#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <string>
#include <vector> // /!\ a enlever une fois ft::vector termine


namespace ft
{
	template <typename T, class Container = std::vector<T> > // /!\ std::vector a remplacer par ft::vector une fois qu'il sera implemente
	class stack
	{
		private :

			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;


		protected :

			Container c;


		public :

			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			explicit stack(const Container & cont = Container()) : c(cont) {};

			stack(const stack & other) : c(other.c) {};

			~stack() {};


			/****************** MEMBER  FUNCTIONS ******************/
			
			stack & operator=(const stack & other) {
				c = other.c;
				return (*this);
			};

			reference top() {
				return (c.back());
			};

			const_reference top() const {
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