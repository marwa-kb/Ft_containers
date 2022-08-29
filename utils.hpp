#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

namespace ft
{
	
	/****************** ENABLE_IF ******************/

	template <bool B, class T = void>
	struct enable_if
	{
	};
 
	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;	
	};


	/***************** IS_INTEGRAL *****************/
/*
	template <class T>
	struct is_integral
	{
		typedef bool								value_type;
		typedef std::integral_constant<bool, value>	type;

		static value_type value const;

		value_type operator bool() {
			return (value);
		};
	};

	template <>
	struct is_integral<bool> {};

	template <>
	struct is_integral<char> {};
	
	template <>
	struct is_integral<char16_t> {};
	
	template <>
	struct is_integral<char32_t> {};
	
	template <>
	struct is_integral<wchar_t> {};
	
	template <>
	struct is_integral<signed char> {};
	
	template <>
	struct is_integral<short int> {};
	
	template <>
	struct is_integral<int> {};
	
	template <>
	struct is_integral<long int> {};
	
	template <>
	struct is_integral<long long int> {};
	
	template <>
	struct is_integral<unsigned char> {};

	template <>
	struct is_integral<unsigned short int> {};

	template <>
	struct is_integral<unsigned int> {};

	template <>
	struct is_integral<unsigned long int> {};

	template <>
	struct is_integral<unsigned long long int> {};
*/
}

#endif