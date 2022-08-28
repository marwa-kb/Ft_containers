#ifndef MAP_HPP
# define MAP_HPP

#include <string>

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > //!\ std::pair a recoder
	class map
	{
		private :

			typedef Key							key_type;
			typedef T							mapped_type;
			typedef std::pair<const Key, T>		value_type;
			typedef std::size_t					size_type;
			typedef std::ptrdiff_t				difference_type;
			typedef Compare						key_compare;
			typedef Allocator					allocator_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef Allocator::pointer 			pointer;
			typedef Allocator::const_pointer	const_pointer;
			// typedef iterator	LegacyBidirectionalIterator to value_type;
			// typedef const_iterator	LegacyBidirectionalIterator to const value_type;
			// typedef reverse_iterator	std::reverse_iterator<iterator>;
			// typedef const_reverse_iterator	std::reverse_iterator<const_iterator>;

		public :
	};
}

#endif