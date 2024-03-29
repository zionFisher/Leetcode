#pragma region FORMAT

/* FUCTION: <fuction name>
 *          <comment>
 *
 *          <fuction prototype>
 *          [optional]<example> */

/* CLASS:   <class name>
 *          <comment>
 *          [array]<utility fuction> */

/* DEFINITION: <definition name>
 *             <comment> */

#pragma endregion FORMAT

//! <algorithm>-------------------------------------------------------------------------------------

/* FUCTION: sort()
 *          [Sorts the elements in the range [first, last) in ascending order.]
 *
 *          template< class RandomIt >
 *          void sort( RandomIt first, RandomIt last );
 *          e.g. sort(vector.begin(), vector.end()); */

/* FUCTION: swap()
 *          [Exchanges the given values.]
 *
 *          template< class T >
 *          void swap( T& a, T& b );
 *          e.g. std::swap(a, b); */

//! <cctype>----------------------------------------------------------------------------------------

/* FUCTION: isalnum()
 *          [Checks if the given character is an alphanumeric character.]
 *          [In the default locale, the following characters are alphanumeric:]
 *          [digits (0123456789)]
 *          [uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ)]
 *          [lowercase letters (abcdefghijklmnopqrstuvwxyz)]
 *
 *          int isalnum( int ch ); */

/* FUCTION: isalpha()
 *          [Checks if the given character is an alphabetic character.]
 *          [In the default locale, the following characters are alphabetic:]
 *          [uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ)]
 *          [lowercase letters (abcdefghijklmnopqrstuvwxyz)]
 *
 *          int isalpha( int ch ); */

/* FUCTION: islower()
 *          [Checks if the given character is classified as a lowercase character.]
 *          [islower returns a nonzero value only for the lowercase letters (abcdefghijklmnopqrstuvwxyz).]
 *          [islower returns a zero value if the letter is not a lowercase alphabetic.]
 *
 *          int islower( int ch ); */

/* FUCTION: isupper()
 *          [Checks if the given character is classified as a uppercase character.]
 *          [islower returns a nonzero value only for the uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ).]
 *          [islower returns a zero value if the letter is not a uppercase alphabetic.]
 *
 *          int isupper( int ch ); */

/* FUCTION: isspace()
 *          [Checks if the given character is whitespace character.]
 *          [whitespace characters are the following:]
 *          [space (0x20, ' ') || form feed (0x0c, '\f') || line feed (0x0a, '\n') || carriage return (0x0d, '\r') || horizontal tab (0x09, '\t') || vertical tab (0x0b, '\v')]
 *
 *          int isdigit( int ch ); */

/* FUCTION: isdigit()
 *          [Checks if the given character is one of the 10 decimal digits: 0123456789.]
 *          [Return Non-zero value if the character is a numeric character, zero otherwise.]
 *
 *          int isdigit( int ch ); */

/* FUCTION: tolower()
 *          [Converts the given character to lowercase according to the character conversion rules defined by the currently installed C locale.]
 *
 *          int tolower( int ch ); */

/* FUCTION: toupper()
 *          [Converts the given character to uppercase according to the character conversion rules defined by the currently installed C locale.]
 *
 *          int toupper( int ch );  */

//! <cinttypes>------------------------------------------------------------------------------------

/* DEFINITION: int8_t, int16_t, int32_t, int64_t
 *             [signed integer type with width of exactly 8, 16, 32 and 64 bits respectively with no padding bits and using 2's complement for negative values] */

/* DEFINITION: uint8_t, uint16_t, uint32_t, uint64_t
 *             [unsigned integer type with width of exactly 8, 16, 32 and 64 bits respectively] */

/* DEFINITION: INT8_MAX, INT16_MAX, INT32_MAX, INT64_MAX
 *             [maximum value of an object of type int8_t, int16_t, int32_t, int64_t] */

/* DEFINITION: INT8_MIN, INT16_MIN, INT32_MIN, INT64_MIN
 *             [minimum value of an object of type int8_t, int16_t, int32_t, int64_t] */


//! <climits>--------------------------------------------------------------------------------------

/* DEFINITION: INT_MAX, INT_MIN, CHAR_MAX, CHAR_MIN, LONG_MAX, LONG_MIN
 *             [maximum number and minimum number] */

//! <cmath>----------------------------------------------------------------------------------------

/* FUCTION: pow()
 *          [Computes the value of base raised to the power exp or iexp.]
 *
 *          float  pow ( float base, float exp );   [exp is exponent as a value of floating-point or integral type]
 *          double pow ( double base, double exp );
 *          float  pow ( float base, int iexp );    [iexp is exponent as integer value]
 *          double pow ( double base, int iexp ); */

/* FUCTION: abs(), fabs()
 *          [Computes the absolute value of an integer number or floating point number.]
 *
 *          int    abs  ( int n );
 *          long   abs  ( long n );
 *          float  fabs ( float arg );
 *          double fabs ( double arg ); */

//! <cstdlib>--------------------------------------------------------------------------------------

/* FUCTION: rand()
 *          [Returns a pseudo-random integral value between ​0​ and RAND_MAX (0 and RAND_MAX included).]
 *          [RAND_MAX is guaranteed that this value is at least 32767 and this value is implementation dependent.]
 *          [Each time rand() is seeded with the same seed, it must produce the same sequence of values.]
 *          [If rand() is used before any calls to srand(), rand() behaves as if it was seeded with srand(1).]
 *
 *          int rand();
 *          e.g. std::srand(std::time(nullptr));
 *               int random_variable = std::rand(); */

/* FUCTION: srand()
 *          [Seeds the pseudo-random number generator used by std::rand() with the value seed.]
 *
 *          void srand( unsigned seed );
 *          e.g. see above */

//! <iostream>-------------------------------------------------------------------------------------

/* CLASS: string */

/* FUCTION: swap()
 *          [see also <algorithm>] */

//! <numeric>--------------------------------------------------------------------------------------

/* FUCTION: accumulate()
 *          [Computes the sum of the given value init and the elements in the range [first, last).]
 *
 *          template< class InputIt, class T >
 *          T accumulate( InputIt first, InputIt last, T init );
 *          template< class InputIt, class T, class BinaryOperation >
 *          T accumulate( InputIt first, InputIt last, T init, BinaryOperation op );
 *          e.g. int sum = accumulate(array.begin(), array.end(), 0); */

//! ||STL CONTAINER|| <vector>---------------------------------------------------------------------

/* CLASS: vector
 *        [Vector Implementation based on Array] */

//! ||STL CONTAINER|| <unordered_map>--------------------------------------------------------------

/* CLASS: unordered_map
 *        [Map Implementation based on Hash]
 *        FUCTION: begin()
 *                 [Returns an iterator to the first element of the container.]
 *                 iterator begin() noexcept
 *        FUCTION: end()
 *                 [Returns an iterator to the element following the last element of the container, the iterator point to the past-the-last element.]
 *                 iterator end() noexcept;
 *        FUCTION: empty()
 *                 [Checks if the container has no elements, i.e. whether begin() == end().]
 *                 bool empty() const noexcept;
 *        FUCTION: size()
 *                 [Returns the number of elements in the container, i.e. std::distance(begin(), end()).]
 *                 size_type size() const noexcept;
 *        FUCTION: clear()
 *                 [Erases all elements from the container. After this call, size() returns zero.]
 *                 void clear() noexcept;
 *        FUCTION: insert()
 *                 [Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.]
 *                 std::pair<iterator,bool> insert( value_type&& value );
 *                 e.g. unordered_map<int, string> map;
 *                      map.insert({1, "one"});
 *                      map.insert(make_pair(2, "two"));
 *        FUCTION: erase()
 *                 [Removes the element at pos or in the range [first, last).]
 *                 iterator erase( const_iterator pos );
 *                 iterator erase( const_iterator first, const_iterator last );
 *                 e.g. unordered_map<int, string> map = {{1, "one"}, {2, "two"}};
 *                      auto it = map.begin();
 *                      map.erase(it);
 *        FUCTION: count()
 *                 [Returns the number of elements with key that compares equal to the specified argument key, which is either 1 or 0 since this container does not allow duplicates.]
 *                 size_type count( const Key& key ) const;
 *        FUCTION: find()
 *                 [Finds an element with key equivalent to key.]
 *                 iterator find( const Key& key );
 *        FUCTION: swap()
 *                 [Exchanges the contents of the container with those of other.]
 *                 void swap( unordered_map& other ); */

//! ||STL CONTAINER|| <unordered_set>--------------------------------------------------------------

/* CLASS: unordered_set
 *        [Set Implementation based on Hash]
 *        FUCTION: begin()
 *                 [Returns an iterator to the first element of the container.]
 *                 iterator begin() noexcept
 *        FUCTION: end()
 *                 [Returns an iterator to the element following the last element of the container, the iterator point to the past-the-last element.]
 *                 iterator end() noexcept;
 *        FUCTION: empty()
 *                 [Checks if the container has no elements, i.e. whether begin() == end().]
 *                 bool empty() const noexcept;
 *        FUCTION: size()
 *                 [Returns the number of elements in the container, i.e. std::distance(begin(), end()).]
 *                 size_type size() const noexcept;
 *        FUCTION: clear()
 *                 [Erases all elements from the container. After this call, size() returns zero.]
 *                 void clear() noexcept;
 *        FUCTION: insert()
 *                 [Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.]
 *                 std::pair<iterator,bool> insert( const value_type& value );
 *                 e.g. unordered_set<int> set;
 *                      set.insert(0);
 *        FUCTION: erase()
 *                 [Removes the element at pos or in the range [first, last).]
 *                 iterator erase( const_iterator pos );
 *                 iterator erase( const_iterator first, const_iterator last );
 *        FUCTION: count()
 *                 [Returns the number of elements with key that compares equal to the specified argument key, which is either 1 or 0 since this container does not allow duplicates.]
 *                 size_type count( const Key& key ) const;
 *        FUCTION: find()
 *                 [Finds an element with key equivalent to key.]
 *                 iterator find( const Key& key );
 *        FUCTION: swap()
 *                 [Exchanges the contents of the container with those of other.]
 *                 void swap( unordered_map& other ); */

//! <utility>--------------------------------------------------------------------------------------

/* FUCTION: swap()
 *          [see also <algorithm>] */



using namespace std;