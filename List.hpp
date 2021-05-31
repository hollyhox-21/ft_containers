//
// Created by Retro Joella on 5/19/21.
//

#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP
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
	class List {
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
		typedef struct			s_Node {
			value_type			*_data;
			struct s_Node		*_next;
			struct s_Node		*_prev;
		}						t_Node;
		t_Node					*_lock;
		size_type				_size;
		
		typedef typename	allocator_type::template rebind<t_Node>::other allocator_rebind;
		allocator_type		_alloc_data;
		allocator_rebind	_alloc_node;
		
		void	_create_empty_list() {
			_lock = _alloc_node.allocate(1);
			_lock->_data = _alloc_data.allocate(1);
			_lock->_next = _lock;
			_lock->_prev = _lock;
		}
		
		t_Node	*_new_node(const value_type& data) {
			t_Node *node = _alloc_node.allocate(1);
			node->_data = _alloc_data.allocate(1);
			_alloc_data.construct(node->_data, data);
			node->_next = nullptr;
			node->_prev = nullptr;
			return (node);
		}
		
		void	_clear_node(t_Node *node) {
			_alloc_data.destroy(node->_data);
			_alloc_data.deallocate(node->_data, 1);
			_alloc_node.deallocate(node, 1);
			_size--;
		}
		
		t_Node	*_insert_node(t_Node *first, t_Node *second, const value_type & data) {
			t_Node *tmp = _new_node(data);
			
			first->_next = tmp;
			tmp->_prev = first;
			tmp->_next = second;
			second->_prev = tmp;
			_size++;
			return tmp;
		}
		
		void	_link_node(t_Node *first, t_Node *second) {
			first->_next = second;
			second->_prev = first;
		}
		
		void	_swap_links(iterator it) {
			t_Node *tmp = it._node->_next;
			it._node->_next = it._node->_prev;
			it._node->_prev = tmp;
		}
		
	public:
		explicit List (const allocator_type& alloc = allocator_type()): _alloc_data(alloc), _size(0) {
			_create_empty_list();
		}
		
		
		List (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) : _alloc_data(alloc), _size(0) {
			_create_empty_list();
			while (n > 0) {
				push_front(val);
				n--;
			}
		}
		template <class InputIterator>
		List (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) :
				_alloc_data(alloc), _size(0) {
			_create_empty_list();
			insert(begin(), first, last);
		}
		
		List (const List& x) : _size(0) {
			_alloc_data = x.get_allocator();
			_create_empty_list();
			insert(begin(), x.begin(), x.end());
		}
		
		~List() {
			clear();
			_clear_node(_lock);
		}
		
		List& operator= (const List& x) {
			_size = 0;
			_alloc_data = x.get_allocator();
			_create_empty_list();
			insert(begin(), x.begin(), x.end());
			return *this;
		}
		
		void print_list() {
			t_Node *tmp = _lock->_next;
			int i = 1;
			printf("--------\n");
			while (tmp != _lock) {
				printf("nb[%d] addres_node=>[%p] data=>[%s%d%s] next=>[%p] prev=>[%p]\n",
							i, tmp, BRIGHT_CYAN,*tmp->_data, END, tmp->_next, tmp->_prev);
				tmp = tmp->_next;
				i++;
			}
		}

		class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
			friend class List;
		private:
			t_Node	*_node;
		public:
			iterator() : _node(nullptr) { }
			iterator(t_Node *item) : _node(item) { }
			iterator(const iterator & src) : _node(src._node) { }
			~iterator() { }
			
			iterator&		operator=(const iterator& src) {
				if (this != &src)
					_node = src._node;
				return *this;
			}
			T&			operator*() { return *_node->_data; }
			T*			operator->() { return &(_node->_data); }
			iterator&	operator++() { _node = _node->_next; return *this; }
			iterator&	operator--() { _node =_node->_prev; return *this; }
			iterator&	operator++(int) { iterator ret = *this; _node =_node->_next; return ret; }
			iterator&	operator--(int) { iterator ret = *this; _node =_node->_prev; return ret; }
			bool		operator!=(const iterator & other) const { return _node != other._node; }
			bool		operator==(const iterator & other) const { return _node == other._node; }
			bool		operator!=(const const_iterator & other) const { return _node != other._node; }
			bool		operator==(const const_iterator & other) const { return _node == other._node; }
		};
		
		class const_iterator : public std::iterator<std::bidirectional_iterator_tag, const T> {
			friend class List;
		private:
			t_Node	*_node;
		public:
			const_iterator() : _node(nullptr) { }
			const_iterator(t_Node *item) : _node(item) { }
			const_iterator(const iterator & src) : _node(src._node) { }
			const_iterator(const const_iterator & src) : _node(src._node) { }
			~const_iterator() { }
			
			const_iterator&		operator=(const iterator& src) {
				if (this != &src)
					_node = src._node;
				return *this;
			}
			T&				operator*() { return *_node->_data; }
			const T*		operator->() { return &(_node->_data); }
			const_iterator&	operator++() { _node = _node->_next; return *this; }
			const_iterator&	operator--() { _node =_node->_prev; return *this; }
			const_iterator&	operator++(int) { const_iterator ret = *this; _node =_node->_next; return ret; }
			const_iterator&	operator--(int) { const_iterator ret = *this; _node =_node->_prev; return ret; }
			bool			operator!=(const const_iterator & other) const { return _node != other._node; }
			bool			operator==(const const_iterator & other) const { return _node == other._node; }
			bool			operator!=(const iterator & other) const { return _node != other._node; }
			bool			operator==(const iterator & other) const { return _node == other._node; }
		};
		
		class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
			friend class List;
		private:
			t_Node	*_node;
		public:
			reverse_iterator() : _node(nullptr) { }
			reverse_iterator(t_Node *item) : _node(item) { }
			reverse_iterator(const iterator & src) : _node(src._node) { }
			~reverse_iterator() { }
			
			reverse_iterator&		operator=(const iterator& src) {
				if (this != &src)
					_node = src._node;
				return *this;
			}
			T&				operator*() { return *_node->_data; }
			const T*		operator->() { return &(_node->_data); }
			reverse_iterator&	operator++() { _node = _node->_prev; return *this; }
			reverse_iterator&	operator--() { _node =_node->_next; return *this; }
			reverse_iterator&	operator++(int) { iterator ret = *this; _node =_node->_prev; return ret; }
			reverse_iterator&	operator--(int) { iterator ret = *this; _node =_node->_next; return ret; }
			bool		operator!=(const reverse_iterator & other) const { return _node != other._node; }
			bool		operator==(const reverse_iterator & other) const { return _node == other._node; }
			bool		operator!=(const const_reverse_iterator & other) const { return _node != other._node; }
			bool		operator==(const const_reverse_iterator & other) const { return _node == other._node; }
		};
		
		class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
			friend class List;
		private:
			t_Node	*_node;
		public:
			const_reverse_iterator() : _node(nullptr) { }
			const_reverse_iterator(t_Node *item) : _node(item) { }
			const_reverse_iterator(const reverse_iterator & src) : _node(src._node) { }
			const_reverse_iterator(const const_reverse_iterator & src) : _node(src._node) { }
			~const_reverse_iterator() { }
			
			const_reverse_iterator&		operator=(const iterator& src) {
				if (this != &src)
					_node = src._node;
				return *this;
			}
			T&				operator*() { return *_node->_data; }
			const T*		operator->() { return &(_node->_data); }
			const_reverse_iterator&	operator++() { _node = _node->_prev; return *this; }
			const_reverse_iterator&	operator--() { _node =_node->_next; return *this; }
			const_reverse_iterator&	operator++(int) { const_iterator ret = *this; _node =_node->_prev; return ret; }
			const_reverse_iterator&	operator--(int) { const_iterator ret = *this; _node =_node->_next; return ret; }
			bool			operator!=(const const_reverse_iterator & other) const { return _node != other._node; }
			bool			operator==(const const_reverse_iterator & other) const { return _node == other._node; }
			bool			operator!=(const reverse_iterator & other) const { return _node != other._node; }
			bool			operator==(const reverse_iterator & other) const { return _node == other._node; }
		};
		
//==================>>>Iterators<<<====================
		iterator begin(){
			iterator it(_lock->_next);
			return it;
		}
		
		const_iterator begin() const {
			const_iterator it(_lock->_next);
			return it;
		}
		
		iterator end() {
			iterator it(_lock);
			return it;
		}
		
		const_iterator end() const {
			const_iterator it(_lock);
			return it;
		}
		
		reverse_iterator rbegin() {
			reverse_iterator it(_lock->_prev);
			return it;
		}
		
		const_reverse_iterator rbegin() const {
			const_reverse_iterator it(_lock->_prev);
			return it;
		}
		
		reverse_iterator rend() {
			reverse_iterator it(_lock);
			return it;
		}
		
		const_reverse_iterator rend() const {
			const_reverse_iterator it(_lock);
			return it;
		}

//==================>>>END__Iterators<<<====================

//==================>>>Capacity<<<====================
		size_type size() const{
			return _size;
		}
		
		bool	empty() const{
			return _size == 0 ? true : false;
		}
		
		size_type max_size() const {
			return UINT64_MAX / sizeof(t_Node);
		}
//==================>>>END__Capacity<<<====================

//==================>>>Element access<<<====================
		reference front() {
			reference tmp = *(_lock->_next->_data);
			return tmp;
		}
		
		const_reference front() const {
			const_reference tmp = *(_lock->_next->_data);
			return tmp;
		}
		
		reference back() {
			reference tmp = *(_lock->_prev->_data);
			return tmp;
		}
		
		const_reference back() const {
			const_reference tmp = *(_lock->_prev->_data);
			return tmp;
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
		
		void push_front (const value_type& val) {
			_insert_node(_lock, _lock->_next, val);
		}
		
		void pop_front() {
			t_Node *tmp = _lock->_next;
			
			_link_node(_lock, tmp->_next);
			_clear_node(tmp);
		}
		
		void push_back (const value_type& val) {
			_insert_node(_lock->_prev, _lock, val);
		}
		
		void pop_back() {
			t_Node *tmp = _lock->_prev;
			
			_link_node(tmp->_prev, _lock);
			_clear_node(tmp);
		}
		
		iterator insert (iterator position, const value_type& val) {
			List::iterator res;
			
			res._node = _insert_node(position._node->_prev, position._node, val);
			return res;
		}
		
		void insert (iterator position, size_type n, const value_type& val) {
			for (; n > 0; n--)
				_insert_node(position._node->_prev, position._node, val);
		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			for (; first != last; first++)
				_insert_node(position._node->_prev, position._node, *first);
		}
		
		iterator erase (iterator position) {
			iterator tmp = position._node->_next;
			_link_node(position._node->_prev, position._node->_next);
			_clear_node(position._node);
			return tmp;
		}
		
		iterator erase (iterator first, iterator last) {
			iterator tmp = last._node->_next;
			_link_node(first._node->_prev, last._node);
			for ( ; first != last; first++)
				_clear_node(first._node);
			return tmp;
		}
		
		void swap (List& x) {
			size_type tmp_size = x._size;
			x._size = _size;
			_size = tmp_size;
			
			t_Node *tmp_lock = x._lock;
			x._lock = _lock;
			_lock = tmp_lock;
		}
		
		void resize (size_type n, value_type val = value_type()) {
			if (_size < n) {
				for ( ; _size != n; )
					push_back(val);
			}
			else {
				for ( ; _size != n; )
					pop_back();
			}
		}
		
		void clear() {
			for ( ; _size; )
				pop_back();
		}
//==================>>>END__Modifiers<<<====================

//==================>>>Operations<<<====================
		void splice (iterator position, List& x) {
			iterator it = x.begin();
			iterator it_e = x.end();
			insert(position, it, it_e);
			x.clear();
		}
		
		void splice (iterator position, List& x, iterator i) {
			insert(position, *i);
			x.erase(i);
		}
		
		void splice (iterator position, List& x, iterator first, iterator last) {
			insert(position, first, last);
			x.erase(first, last);
		}
		
		void remove (const value_type& val) {
			iterator it = begin();
			iterator it_e = end();
			for ( ; it != it_e; it++) {
				if (*it == val)
					erase(it);
			}
		}
		
		template <class Predicate>
		void remove_if (Predicate pred) {
			iterator it = begin();
			iterator it_e = end();
			for ( ; it != it_e; it++) {
				if (pred(*it))
					erase(it);
			}
		}
		
		void unique() {
		
		}
		
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred) {
		
		}
		
		void merge (List& x) {
			iterator it_this = begin();
			iterator it_e_this = end();
			iterator it_x = x.begin();
			iterator it_e_x = x.end();
			
			while (it_this != it_e_this) {
				if (*it_this < *it_x) {
					it_this++;
				}
				else {
					splice(it_this, x, it_x);
					it_x++;
				}
			}
			splice(it_this, x, it_x, it_e_x);
		}
		
		template <class Compare>
		void merge (List& x, Compare comp) {
			iterator it_this = begin();
			iterator it_e_this = end();
			iterator it_x = x.begin();
			iterator it_e_x = x.end();
			
			while (it_this != it_e_this) {
				if (comp(*it_this, *it_x)) {
					it_this++;
				}
				else {
					splice(it_this, x, it_x);
					it_x++;
				}
			}
			splice(it_this, x, it_x, it_e_x);
		}
		
		void sort() {
			size_type mid;
			iterator start_l = begin();
			iterator end_l = start_l;
			iterator start_r;
			iterator end_r = end();
			List<value_type> right;
			
			if (size() > 1) {
				mid = size() / 2;
				for (int i = mid; i > 1; i--)
					end_l++;
				if (size() % 2)
					start_r = ++end_l;
				else
					start_r = ++end_l;
				
				right.splice(right.begin(), *this, start_r, end_r);
//				sort_left
				sort();
//				sort_right
				right.sort();
//				merge left and right
				merge(right);
			}
		}
		
		template <class Compare>
		void sort (Compare comp) {
			size_type mid;
			iterator start_l = begin();
			iterator end_l = start_l;
			iterator start_r;
			iterator end_r = end();
			List<value_type> right;
			
			if (size() > 1) {
				mid = size() / 2;
				for (int i = mid; i > 1; i--)
					end_l++;
				start_r = ++end_l;
				right.splice(right.begin(), *this, start_r, end_r);
//				sort_left
				sort();
//				sort_right
				right.sort();
//				merge left and right
				merge(right, comp);
			}
		}
		
		void reverse() {
			iterator it = begin();
			iterator it_e = end();
			_swap_links(it_e);
			while (it != it_e++)
				_swap_links(it_e);
		}
//==================>>>END__Operations<<<====================

//==================>>>Observers<<<====================
		allocator_type get_allocator() const { return _alloc_data; }
//==================>>>END__Observers<<<====================
	};
	
//==================>>>Relational operators<<<====================
	template <class T>
	bool	_cmp_on_equality(const List<T>& lhs, const List<T>& rhs) {
		typename ft::List<T>::const_iterator it_l = lhs.begin();
		typename ft::List<T>::const_iterator it_r = rhs.begin();
		typename ft::List<T>::const_iterator it_l_e = lhs.end();
		
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
	bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
		if (lhs.size() == rhs.size())
			return _cmp_on_equality(lhs, rhs);
		else {
			return false;
		}
	}
	
	template <class T, class Alloc>
	bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) { return !(lhs == rhs);}
	
	template <class T, class Alloc>
	bool operator< (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) { return (*lhs.begin() < *rhs.begin()); }
	
	template <class T, class Alloc>
	bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) { return (*lhs.begin() <= *rhs.begin()); }
	
	template <class T, class Alloc>
	bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) { return (*lhs.begin() > *rhs.begin()); }
	
	template <class T, class Alloc>
	bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) { return (*lhs.begin() >= *rhs.begin()); }
	
	template <class T, class Alloc>
	void swap (List<T,Alloc>& x, List<T,Alloc>& y) { x.swap(y); }
//==================>>>END__Relational operators<<<====================
}

#endif //FT_CONTAINERS_LIST_HPP
