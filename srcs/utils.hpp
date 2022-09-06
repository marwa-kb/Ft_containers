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


	/*********** LEXICOGRAPHICAL_COMPARE ***********/

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
 	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                            	Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}


	/******************** EQUAL ********************/

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
 	bool equal(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
}

#endif