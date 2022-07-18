#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <string>
#include <cstddef>


namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		private :

			T											value_type;
			Allocator 									allocator_type;
			typedef typename std::size_t				size_type;
			typedef typename std::ptrdiff_t				difference_type;
			typedef typename value_type&				reference;
			typedef typename value_type& const			const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;


		public :

			/************* CONSTRUCTOR AND  DESTRUCTOR *************/

			vector();

			explicit vector(const Allocator & alloc);

			explicit vector(size_type count, const T & value = T(), const Allocator& alloc = Allocator());
				 
			template <class InputIt>
			vector(InputIt first, InputIt last, const Allocator & alloc = Allocator());

			vector(const vector & other);

			~vector() {};


			/********************** OPERATORS **********************/
			
			vector & operator=(const vector & other) {
				//
				(void)other;
				return (*this);
			};
			
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

			/****************** MEMBER  FUNCTIONS ******************/
			
			allocator_type get_allocator() const {
				return (allocator_type);
			};

			// reference top() {
			// 	return (c.back());
			// };

			// const_reference top() const {
			// 	return (c.back());
			// };

			// bool empty() const {
			// 	return (c.empty());
			// };

			// size_type size() const {
			// 	return (c.size());
			// };

			// void push(const value_type & value) {
			// 	c.push_back(value);
			// };

			// void pop() {
			// 	c.pop_back();
			// };

	};
}


#endif