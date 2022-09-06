#ifndef UTILS_HPP
# define UTILS_HPP

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
	
	template <class T, T v>
	struct integral_constant
	{
		typedef T							value_type;
	   	typedef ft::integral_constant<T,v>	type;

		static const T value = v;

		operator value_type() const {
			return (value);
		}
	};

	typedef ft::integral_constant<bool, true>	true_type;
	typedef ft::integral_constant<bool, false>	false_type;

	template <class T>
	struct is_integral
	{
		typedef bool								value_type;

		static const value_type value = false;

		typedef ft::integral_constant<bool, value>	type;

		operator bool() {
			return (value);
		};
	};

	template <>
	struct is_integral<bool> : public true_type {};

	template <>
	struct is_integral<char> : public true_type {};
	
	template <>
	struct is_integral<wchar_t> : public true_type {};
	
	template <>
	struct is_integral<signed char> : public true_type {};
	
	template <>
	struct is_integral<short int> : public true_type {};
	
	template <>
	struct is_integral<int> : public true_type {};
	
	template <>
	struct is_integral<long int> : public true_type {};
	
	template <>
	struct is_integral<long long int> : public true_type {};
	
	template <>
	struct is_integral<unsigned char> : public true_type {};

	template <>
	struct is_integral<unsigned short int> : public true_type {};

	template <>
	struct is_integral<unsigned int> : public true_type {};

	template <>
	struct is_integral<unsigned long int> : public true_type {};

	template <>
	struct is_integral<unsigned long long int> : public true_type {};

}

#endif