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
		
		void	_clean_segment(value_type *&arr) {
			_alloc_data.destroy(arr + _size);
			_size--;
		}
		
		void	_clean_arr(value_type *&arr) {
			for (int i = 0; i < _size; ++i) {
				_alloc_data.destroy(arr + i);
			}
			_alloc_data.deallocate(arr, _capacity);
			_size = 0;
			_capacity = 0;
			arr = nullptr;
		}
		
		void	_insert_obj(const value_type & val) {
			if (_capacity == 0) {
				_array = _alloc_data.allocate(1);
				_alloc_data.construct(_array, val);
				_size++;
				_capacity++;
			}
			else {
				_alloc_data.construct(_array + _size, val);
				_size++;
			}
		}
		
		void	_insert_obj(iterator position, const value_type& val) {
			_alloc_data.destroy(&(*position));
			_alloc_data.construct(&(*position), val);
			_size++;
		}
		
		void	_realloc_memory(size_type n) {
			size_type	tmp_capacity = n;
			size_type	tmp_size = _size;
			value_type	*tmp_arr = _alloc_data.allocate(tmp_capacity);
			
			for (int i = 0; i < _size; ++i)
				_alloc_data.construct(tmp_arr + i, _array[i]);
			_clean_arr(_array);
			_array = tmp_arr;
			_size = tmp_size;
			_capacity = tmp_capacity;
		}
		
		void	_move_right(iterator position) {
			iterator it_e = end();
			for (;position != it_e; --it_e)
				it_e[1] = *it_e;
			it_e[1] = *it_e;
		}
		
		void	_move_left(iterator position) {
			_alloc_data.destroy(&(*position));
			iterator it_e = end();
			for (; position != it_e; ++position)
				*position = position[1];
		}
	
	public:
		void	_print_vec() {
			std::cout << "|------------------" << std::endl;
			std::cout << "|\t[ ";
			for (int i = 0; i < _capacity; ++i) {
				std::cout << (i == 0 ? BRIGHT_CYAN : "") << _array[i] << " " ;
				if (i + 1 == _size)
					std::cout << END << "| ";
			}
			std::cout << "] \n";
			std::cout << "|\t" << BRIGHT_GREEN << "SIZE = " << END << _size << " | "
			<< BRIGHT_RED << "CAPACITY = " << END << _capacity << std::endl;
			std::cout << "|------------------" << std::endl;
		}
		
	public:
		vector (const allocator_type& alloc = allocator_type()) :
			_array(nullptr), _size(0), _capacity(0), _alloc_data(alloc) { }
		
		vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) :
			_array(nullptr), _size(0), _capacity(0), _alloc_data(alloc) {
			for (int i = 0; i < n; ++i) {
				push_back(val);
			}
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) :
			_array(nullptr), _size(0), _capacity(0), _alloc_data(alloc) {
			insert(begin(), first, last);
		}

		vector (const vector& x) {
			_alloc_data = x.get_allocator();
			insert(begin(), x.begin(), x.end());
		}

		~vector() {
			clear();
		}
		
		vector& operator= (const vector& x) {
			_array = nullptr;
			_size = 0;
			_capacity = 0;
			_alloc_data = x.get_allocator();
			insert(begin(), x.begin(), x.end());
			return *this;
		}
		
	class iterator : public std::iterator<std::random_access_iterator_tag, const T> {
			friend class vector;
	private:
			value_type *_cure_item;
	public:
		iterator() : _cure_item(nullptr) { }
		iterator(value_type *item) : _cure_item(item) { }
		iterator(const iterator & src) : _cure_item(src._cure_item) { }
		~iterator() { }
		
		iterator&	operator=(const iterator &src) {
			if (this != &src)
				_cure_item = src._cure_item;
			return *this;
		}
		value_type&	operator*() const { return *_cure_item; }
		value_type*	operator->() const { return &_cure_item; }
		iterator&	operator++() { _cure_item++; return *this; }
		iterator&	operator--() { _cure_item--; return *this; }
		iterator&	operator++(int) { iterator ret = *this; _cure_item++; return ret;  }
		iterator&	operator--(int) { iterator ret = *this; _cure_item--; return ret;  }
		bool		operator!=(const iterator & other) const { return _cure_item != other._cure_item; }
		bool		operator==(const iterator & other) const { return _cure_item == other._cure_item;  }
		bool		operator!=(const const_iterator & other) const { return _cure_item != other._cure_item; }
		bool		operator==(const const_iterator & other) const { return _cure_item == other._cure_item; }
		
		bool 		operator<(const iterator & other) const {return _cure_item < other._cure_item ;}
		bool 		operator>(const iterator & other) const {return _cure_item > other._cure_item ;}
		bool 		operator<=(const iterator & other) const {return _cure_item <= other._cure_item ;}
		bool 		operator>=(const iterator & other) const {return _cure_item >= other._cure_item ;}
		
		iterator&	operator+(difference_type n) { _cure_item += n; return *this; }
		difference_type operator-(iterator &other) {return _cure_item - other._cure_item ;}
		iterator&	operator-(difference_type n) { _cure_item -= n; return *this; }
		iterator&	operator+=(difference_type n) { _cure_item += n; return *this; }
		iterator&	operator-=(difference_type n) { _cure_item -= n; return *this; }
		value_type&	operator[](difference_type n) { return *(_cure_item + n); }
		};

	class const_iterator : public std::iterator<std::random_access_iterator_tag, const T> {
		friend class vector;
	private:
		value_type *_cure_item;
	public:
		const_iterator() : _cure_item(nullptr) { }
		const_iterator(value_type *item) : _cure_item(item) { }
		const_iterator(const iterator & src) : _cure_item(src._cure_item) { }
		const_iterator(const const_iterator & src) : _cure_item(src._cure_item) { }
		~const_iterator() { }
	
		const_iterator&	operator=(const const_iterator &src) {
			if (this != &src)
				_cure_item = src._cure_item;
			return *this;
		}
		value_type&		operator*() const { return *_cure_item; }
		value_type*		operator->() const { return &_cure_item; }
		const_iterator&	operator++() { _cure_item++; return *this; }
		const_iterator&	operator--() { _cure_item--; return *this; }
		const_iterator&	operator++(int) { const_iterator ret = *this; _cure_item++; return ret;  }
		const_iterator&	operator--(int) { const_iterator ret = *this; _cure_item--; return ret;  }
		bool			operator!=(const iterator & other) const { return _cure_item != other._cure_item; }
		bool			operator==(const iterator & other) const { return _cure_item == other._cure_item;  }
		bool			operator!=(const const_iterator & other) const { return _cure_item != other._cure_item; }
		bool			operator==(const const_iterator & other) const { return _cure_item == other._cure_item; }
		
		bool 			operator<(const const_iterator & other) const {return _cure_item < other._cure_item ;}
		bool 			operator>(const const_iterator & other) const {return _cure_item > other._cure_item ;}
		bool 			operator<=(const const_iterator & other) const {return _cure_item <= other._cure_item ;}
		bool 			operator>=(const const_iterator & other) const {return _cure_item >= other._cure_item ;}
		
		const_iterator&	operator+(difference_type n) { _cure_item += n; return *this; }
		const_iterator&	operator-(difference_type n) { _cure_item -= n; return *this; }
		difference_type operator-(const_iterator &other) {return _cure_item - other._cure_item ;}
		const_iterator&	operator+=(difference_type n) { _cure_item += n; return *this; }
		const_iterator&	operator-=(difference_type n) { _cure_item -= n; return *this; }
		value_type&		operator[](difference_type n) { return *(_cure_item + n); }
	};

	class reverse_iterator : public std::iterator<std::random_access_iterator_tag, const T> {
		friend class vector;
	private:
		value_type *_cure_item;
	public:
		reverse_iterator() : _cure_item(nullptr) { }
		reverse_iterator(value_type *item) : _cure_item(item) { }
		reverse_iterator(const reverse_iterator & src) : _cure_item(src._cure_item) { }
		~reverse_iterator() { }
		
		reverse_iterator&	operator=(const reverse_iterator &src) {
			if (this != &src)
				_cure_item = src._cure_item;
			return *this;
		}
		value_type&	operator*() const { return *_cure_item; }
		value_type*	operator->() const { return &_cure_item; }
		reverse_iterator&	operator++() { _cure_item--; return *this; }
		reverse_iterator&	operator--() { _cure_item++; return *this; }
		reverse_iterator&	operator++(int) { reverse_iterator ret = *this; _cure_item--; return ret;  }
		reverse_iterator&	operator--(int) { reverse_iterator ret = *this; _cure_item++; return ret;  }
		bool		operator!=(const reverse_iterator & other) const { return _cure_item != other._cure_item; }
		bool		operator==(const reverse_iterator & other) const { return _cure_item == other._cure_item;  }
		bool		operator!=(const const_reverse_iterator & other) const { return _cure_item != other._cure_item; }
		bool		operator==(const const_reverse_iterator & other) const { return _cure_item == other._cure_item; }
		
		bool 		operator<(const reverse_iterator & other) const {return _cure_item < other._cure_item ;}
		bool 		operator>(const reverse_iterator & other) const {return _cure_item > other._cure_item ;}
		bool 		operator<=(const reverse_iterator & other) const {return _cure_item <= other._cure_item ;}
		bool 		operator>=(const reverse_iterator & other) const {return _cure_item >= other._cure_item ;}
		
		reverse_iterator&	operator+(difference_type n) { _cure_item -= n; return *this; }
		reverse_iterator&	operator-(difference_type n) { _cure_item += n; return *this; }
		reverse_iterator&	operator+=(difference_type n) { _cure_item -= n; return *this; }
		reverse_iterator&	operator-=(difference_type n) { _cure_item += n; return *this; }
		value_type&	operator[](difference_type n) { return *(_cure_item - n); }
	};

	class const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, const T> {
		friend class vector;
	private:
		value_type *_cure_item;
	public:
		const_reverse_iterator() : _cure_item(nullptr) { }
		const_reverse_iterator(value_type *item) : _cure_item(item) { }
		const_reverse_iterator(const const_reverse_iterator & src) : _cure_item(src._cure_item) { }
		~reverse_iterator() { }
		
		const_reverse_iterator&	operator=(const const_reverse_iterator &src) {
			if (this != &src)
				_cure_item = src._cure_item;
			return *this;
		}
		value_type&	operator*() const { return *_cure_item; }
		value_type*	operator->() const { return &_cure_item; }
		const_reverse_iterator&	operator++() { _cure_item--; return *this; }
		const_reverse_iterator&	operator--() { _cure_item++; return *this; }
		const_reverse_iterator&	operator++(int) { const_reverse_iterator ret = *this; _cure_item--; return ret;  }
		const_reverse_iterator&	operator--(int) { const_reverse_iterator ret = *this; _cure_item++; return ret;  }
		bool		operator!=(const reverse_iterator & other) const { return _cure_item != other._cure_item; }
		bool		operator==(const reverse_iterator & other) const { return _cure_item == other._cure_item;  }
		bool		operator!=(const const_reverse_iterator & other) const { return _cure_item != other._cure_item; }
		bool		operator==(const const_reverse_iterator & other) const { return _cure_item == other._cure_item; }
		
		bool 		operator<(const const_reverse_iterator & other) const {return _cure_item < other._cure_item ;}
		bool 		operator>(const const_reverse_iterator & other) const {return _cure_item > other._cure_item ;}
		bool 		operator<=(const const_reverse_iterator & other) const {return _cure_item <= other._cure_item ;}
		bool 		operator>=(const const_reverse_iterator & other) const {return _cure_item >= other._cure_item ;}
		
		const_reverse_iterator&	operator+(difference_type n) { _cure_item -= n; return *this; }
		const_reverse_iterator&	operator-(difference_type n) { _cure_item += n; return *this; }
		const_reverse_iterator&	operator+=(difference_type n) { _cure_item -= n; return *this; }
		const_reverse_iterator&	operator-=(difference_type n) { _cure_item += n; return *this; }
		value_type&	operator[](difference_type n) { return *(_cure_item - n); }
	};
	
//==================>>>Iterators<<<====================
		iterator begin() {
			iterator it(&_array[0]);
			return it;
		}
		
		const_iterator begin() const {
			const_iterator it(&_array[0]);
			return it;
		}

		iterator end() {
			iterator it(&_array[_size]);
			return it;
		}

		const_iterator end() const {
			const_iterator it(&_array[_size]);
			return it;
		}

		reverse_iterator rbegin() {
			reverse_iterator it(&_array[_size]);
			return it;
		}

		const_reverse_iterator rbegin() const {
			const_reverse_iterator it(&_array[_size]);
			return it;
		}

		reverse_iterator rend() {
			reverse_iterator it(&_array[0]);
			return it;
		}

		const_reverse_iterator rend() const {
			const_reverse_iterator it(&_array[0]);
			return it;
		}

//==================>>>END__Iterators<<<=================

//==================>>>Capacity<<<====================
		bool empty() const { return _size == 0 ? true : false; }
		
		size_type size() const { return _size; }
		
		size_type max_size() const { return UINT64_MAX / sizeof(value_type); }
		
		void resize (size_type n, value_type val = value_type()) {
			if (n < _size) {
				for (; n < _size ;) {
					pop_back();
				}
			}
			else {
				for (; n > _size ;) {
					push_back(val);
				}
			}
		}
		
		size_type capacity() const { return _capacity; }
		
		void reserve (size_type n) {
			_realloc_memory(n);
		}
//==================>>>END__Capacity<<<====================

//==================>>>Element access<<<====================
		reference operator[] (size_type n) {
			reference res = *(_array + n);
			return res;
		}
		
		const_reference operator[] (size_type n) const {
			const_reference res = *(_array + n);
			return res;
		}
		
		reference at (size_type n) {
			reference res = *(_array + n);
			return res;
		}
		
		const_reference at (size_type n) const {
			const_reference res = *(_array + n);
			return res;
		}
		
		reference front() {
			reference res = *(_array);
			return res;
		}
		
		const_reference front() const {
			const_reference res = *(_array);
			return res;
		}
		
		reference back() {
			reference res = *(_array + _size - 1);
			return res;
		}
		
		const_reference back() const {
			const_reference res = *(_array + _size - 1);
			return res;
		}
//==================>>>END__Element access<<<====================

//==================>>>Modifiers<<<====================
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
		typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			clear();
			for (; first != last; first++)
				push_back(*first);
		}

		void assign (size_type n, const value_type& val) {
			clear();
			for (; n > 0; n--)
				push_back(val);
		}
		
		void push_back (const value_type& val) {
			if (_size == _capacity && _capacity != 0)
				_realloc_memory(_capacity * 2);
			_insert_obj(val);
		}
		
		void pop_back() {
			_clean_segment(_array);
		}
		
		iterator insert (iterator position, const value_type& val) {
			size_type n = position._cure_item - _array;
			if (_size < _capacity) {
				_move_right(position);
				_insert_obj(position, val);
			}
			else {
				_realloc_memory(_capacity * 2);
				position = begin() + n;
				_move_right(position);
				_insert_obj(position, val);
			}
			return position;
		}

		void insert (iterator position, size_type n, const value_type& val) {
			for (; n > 0; n--)
				position = insert(position, val);
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			for (; first != last; ++first) {
				position = insert(position, *first);
				position++;
			}
		}

		iterator erase (iterator position) {
			_move_left(position);
			_size--;
			return position;
		}

		iterator erase (iterator first, iterator last) {
			int range = last._cure_item - first._cure_item;
			for (int i = 0; i < range; i++)
				first = erase(first);
			return first;
		}
		
		void swap (vector& x) {
			size_type tmp_size = x._size;
			x._size = _size;
			_size = tmp_size;
			
			size_type tmp_capacity = x._capacity;
			x._capacity  = _capacity ;
			_capacity = tmp_capacity ;
			
			value_type * tmp_arr = x._array;
			x._array = _array;
			_array = tmp_arr;
		}
		
		void clear() {
			_clean_arr(_array);
		}
//==================>>>END__Modifiers<<<====================

//==================>>>END__Observers<<<====================
		allocator_type get_allocator() const { return _alloc_data; }
//==================>>>Observers<<<====================
	};
	
//==================>>>Relational operators<<<====================
	template <class T>
	bool	_cmp_on_equality(const vector<T>& lhs, const vector<T>& rhs) {
		typename ft::vector<T>::const_iterator it_l = lhs.begin();
		typename ft::vector<T>::const_iterator it_r = rhs.begin();
		typename ft::vector<T>::const_iterator it_l_e = lhs.end();
		
		for ( ; it_l != it_l_e; it_l++) {
			if (*it_l == *it_r) {
				it_r++;
				continue;
			}
			else
				return false;
		}
		return true;
	}
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() == rhs.size())
			return _cmp_on_equality(lhs, rhs);
		else {
			return false;
		}
	}
	
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs);}
	
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (*lhs.begin() < *rhs.begin()); }
	
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (*lhs.begin() <= *rhs.begin()); }
	
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (*lhs.begin() > *rhs.begin()); }
	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (*lhs.begin() >= *rhs.begin()); }
	
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
//==================>>>END__Relational operators<<<====================
}
#endif //FT_CONTAINERS_VECTOR_HPP
