#include <string>

namespace ft
{

	template <class Iterator>
	struct iterator_traits
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

			reverse_iterator() {};

			explicit reverse_iterator (iterator_type x) : current(x) {};

			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter> & other) : current(other.current) {};


			/****************** MEMBER  FUNCTIONS ******************/

			iterator_type base() const {
				return (current);
			};

/*			reference operator*() const {

			};

			reference operator+ const {

			};

			reference operator++ const {

			};

			reference operator+= const {

			};

			reference operator- const {

			};

			reference operator-- const {

			};

			reference operator-= const {

			};

			reference operator-> const {

			};

			reference operator[] const {

			};
*/
			
			/**************** NON MEMBER  FUNCTIONS ****************/

			// friend bool operator== (const reverse_iterator<Iterator>& lhs,
            //        const reverse_iterator<Iterator>& rhs);


			// friend bool operator!= (const reverse_iterator<Iterator>& lhs,
            //        const reverse_iterator<Iterator>& rhs);


			// friend bool operator<  (const reverse_iterator<Iterator>& lhs,
            //        const reverse_iterator<Iterator>& rhs);


			// friend bool operator<= (const reverse_iterator<Iterator>& lhs,
            //        const reverse_iterator<Iterator>& rhs);


			// friend bool operator>  (const reverse_iterator<Iterator>& lhs,
            //        const reverse_iterator<Iterator>& rhs);

			// friend bool operator>= (const reverse_iterator<Iterator>& lhs,
            //        const reverse_iterator<Iterator>& rhs);


			// friend reverse_iterator<Iterator> operator+(difference_type n, const reverse_iterator<Iterator>& rev_it);
			
			// friend reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	
	};

}
