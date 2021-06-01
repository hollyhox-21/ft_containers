//
// Created by Retro Joella on 5/31/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP
#include <memory>
#include <iterator>
#include <cstdio>
#define BLACK ("\x1B[30m")
#define RED ("\x1B[31m")
#define GREEN ("\x1B[32m")
#define YELLOW ("\x1B[33m")
#define BLUE ("\x1B[34m")
#define MAGENTA ("\x1B[35m")
#define CYAN  ("\x1B[36m")
#define WHITE ("\x1B[37m")
#define BRIGHT_BLACK ("\x1B[90m")
#define BRIGHT_RED ("\x1B[91m")
#define BRIGHT_GREEN ("\x1B[92m")
#define BRIGHT_YELLOW ("\x1B[93m")
#define BRIGHT_BLUE ("\x1B[94m")
#define BRIGHT_MAGENTA ("\x1B[95m")
#define BRIGHT_CYAN  ("\x1B[96m")
#define BRIGHT_WHITE ("\x1B[97m")
#define BG_BLUE ("\x1B[104m")
#define END ("\033[0m")

namespace ft{
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };
	
	template <class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef T			value_type;
		typedef Alloc		allocator_type;
		typedef ptrdiff_t	difference_type;
		typedef size_t		size_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		class				iterator;
		class				const_iterator;
		class				reverse_iterator;
		class				const_reverse_iterator;
	
	private:
		value_type				*_array;
		size_type				_size;
		size_type				_capacity;
		allocator_type			_alloc_data;
		
		
		
	public:
		vector (const allocator_type& alloc = allocator_type()) {
		
		}
		
		vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) {
		
		}
		
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		
		}
		
		vector (const vector& x) {
		
		}
		
		~vector() {
		
		}
		
		vector& operator= (const vector& x) {
		
		}
		
	class iterator : public std::iterator<std::random_access_iterator_tag, const T> {
			friend class vector;
	private:
			value_type *_array;
	public:
			iterator() {}
			iterator() {}
			iterator(const iterator & src) {}
			~iterator() {}
			
			iterator&	operator=(const iterator &src) {}
		T&			operator*
		T*			operator->
		iterator&	operator++
		iterator&	operator--
		iterator&	operator++
		iterator&	operator--
		bool		operator!=
		bool		operator==
		bool		operator!=
		bool		operator==
		
		iterator&	operator+
		iterator&	operator-
		iterator&	operator+=
		iterator&	operator-=
		iterator&	operator[]
		};
		
	class const_iterator : public std::iterator<std::random_access_iterator_tag, const T> {
		friend class vector;
	private:
		value_type *_array;
	public:
		iterator() {}
		iterator() {}
		iterator(const iterator & src) {}
		~iterator() {}
		
		iterator&	operator=(const iterator &src) {}
		T&			operator*
		T*			operator->
		iterator&	operator++
		iterator&	operator--
		iterator&	operator++
		iterator&	operator--
		bool		operator!=
		bool		operator==
		bool		operator!=
		bool		operator==
		
		iterator&	operator+
		iterator&	operator-
		iterator&	operator+=
		iterator&	operator-=
		iterator&	operator[]
	};
	
	class reverse_iterator : public std::iterator<std::random_access_iterator_tag, const T> {
		friend class vector;
	private:
		value_type *_array;
	public:
		iterator() {}
		iterator() {}
		iterator(const iterator & src) {}
		~iterator() {}
		
		iterator&	operator=(const iterator &src) {}
		T&			operator*
		T*			operator->
		iterator&	operator++
		iterator&	operator--
		iterator&	operator++
		iterator&	operator--
		bool		operator!=
		bool		operator==
		bool		operator!=
		bool		operator==
		
		iterator&	operator+
		iterator&	operator-
		iterator&	operator+=
		iterator&	operator-=
		iterator&	operator[]
	};
	
	class const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, const T> {
		friend class vector;
	private:
		value_type *_array;
	public:
		iterator() {}
		iterator() {}
		iterator(const iterator & src) {}
		~iterator() {}
		
		iterator&	operator=(const iterator &src) {}
		T&			operator*
		T*			operator->
		iterator&	operator++
		iterator&	operator--
		iterator&	operator++
		iterator&	operator--
		bool		operator!=
		bool		operator==
		bool		operator!=
		bool		operator==
		
		iterator&	operator+
		iterator&	operator-
		iterator&	operator+=
		iterator&	operator-=
		iterator&	operator[]
	};
	
//==================>>>Iterators<<<====================
		iterator begin() {
		
		}
		
		const_iterator begin() const {
		
		}
		
		iterator end() {
		
		}
		
		const_iterator end() const {
		
		}
		
		reverse_iterator rbegin() {
		
		}
		
		const_reverse_iterator rbegin() const {
		
		}
		
		reverse_iterator rend() {
		
		}
		
		const_reverse_iterator rend() const {
		
		}

//==================>>>END__Iterators<<<=================

//==================>>>Capacity<<<====================
		bool empty() const {
		
		}
		
		size_type size() const { return _size; }
		
		size_type max_size() const {
		
		}
		
		void resize (size_type n, value_type val = value_type()) {
		
		}
		
		size_type capacity() const {
		
		}
		
		void reserve (size_type n) {
		
		}
//==================>>>END__Capacity<<<====================

//==================>>>Element access<<<====================
		reference operator[] (size_type n) {
		
		}
		
		const_reference operator[] (size_type n) const {
		
		}
		
		reference at (size_type n) {
		
		}
		
		const_reference at (size_type n) const {
		
		}
		
		reference front() {
		
		}
		
		const_reference front() const {
		
		}
		
		reference back() {
		
		}
		
		const_reference back() const {
		
		}
//==================>>>END__Element access<<<====================

//==================>>>Modifiers<<<====================
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
		
		}

		void assign (size_type n, const value_type& val) {
		
		}
		
		void push_back (const value_type& val) {
		
		}
		
		void pop_back() {
		
		}
		
		iterator insert (iterator position, const value_type& val) {
		
		}

		void insert (iterator position, size_type n, const value_type& val) {
		
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
		
		}
		
		iterator erase (iterator position) {
		
		}
		
		iterator erase (iterator first, iterator last) {
		
		}
		
		void swap (vector& x) {
		
		}
		
		void clear() {
		
		}
//==================>>>END__Modifiers<<<====================

//==================>>>END__Observers<<<====================
		allocator_type get_allocator() const { return _alloc_data; }
//==================>>>Observers<<<====================
	};
	
//==================>>>Relational operators<<<====================
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	
	}
	
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	
	}
	
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	
	}
	
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	
	}
	
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	
	}
	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	
	}
	
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
//==================>>>END__Relational operators<<<====================
}
#endif //FT_CONTAINERS_VECTOR_HPP
