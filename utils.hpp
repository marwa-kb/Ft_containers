#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

namespace ft
{
	// template <class T>
	// struct is_integral
	// {
	// 	typedef bool								value_type;
	// 	typedef std::integral_constant<bool, value>	type;

	// 	static value_type value const;

	// 	operator bool();
	// };

	template <bool B, class T = void>
	struct enable_if
	{
	};
 
	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;	
	};

}

#endif