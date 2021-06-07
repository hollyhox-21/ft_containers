#include <iostream>
#include "List.hpp"
#include "Vector.hpp"
#include <list>
#include <string>
#include <cmath>
#include <vector>

void print_list(std::list<int> list)
{
	auto it = list.begin();
	auto it_e = list.end();
	
	while (it != it_e)
	{
		std::cout << *it << " " ;
		it++;
	}
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};
// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

bool comparator(int first, int second)
{
	return first < second;
}

bool mycomparison (int first, int second)
{ return ( int(first)<int(second) ); }

size_t random_size_t(size_t min, size_t max) {
	return (max - min) * ((((size_t) rand()) / (size_t) RAND_MAX)) + min;
}
//bool compare_nocase (const std::string& first, const std::string& second)
//{
//	unsigned int i=0;
//	while ( (i<first.length()) && (i<second.length()) )
//	{
//		if (tolower(first[i])<tolower(second[i])) return true;
//		else if (tolower(first[i])>tolower(second[i])) return false;
//		++i;
//	}
//	return ( first.length() < second.length() );
//}

bool compare_nocase (const int & first, const int & second) { return (first > second); }

template <class T>
void	print_cont(T & vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "SIZE = " << vec.size() << std::endl;
	std::cout << "CAPACITY = " << vec.capacity() << std::endl;
}

int main() {
	srand(time(0));
//	std::list<int>	orig;
//	orig.push_front(11);
//	orig.push_front(22);
//	orig.push_front(33);
//	orig.push_front(44);
//	orig.push_front(55);
//	ft::List<int>	my;
//	my.push_front(11);
//	my.push_front(22);
//	my.push_front(33);
//	my.push_front(44);
//	my.push_front(55);
////	my.push_front(15);
////	my.push_back(-5);
////	my.print_list();
////	my.pop_front();
////	my.pop_back();
////	my.print_list();
//
////	std::list<int>::iterator orig_it = orig.begin();
////	std::list<int>::iterator orig_it_e = orig.end();
////	std::list<int>::const_iterator c_orig_it = orig.begin();
////	std::list<int>::const_iterator c_orig_it_e = orig.end();
////
////
////	ft::List<int>::iterator it = my.begin();
////	ft::List<int>::iterator it_e = my.end();
////	ft::List<int>::const_iterator c_it = my.begin();
////	ft::List<int>::const_iterator c_it_e = my.end();
//
////	std::cout << *it << std::endl;
////	std::cout << *orig_it << std::endl;
////
////	std::cout << *it++ << std::endl;
////	std::cout << *orig_it++ << std::endl;
////
////	std::cout << *(++it) << std::endl;
////	std::cout << *(++orig_it) << std::endl;
////
////	std::cout << *(it++) << std::endl;
////	std::cout << *(orig_it++) << std::endl;
////
////	it_e++;
////	*it = *it_e;
////	std::cout << *it << std::endl;
////
////	orig_it_e++;
////	*orig_it = *orig_it_e;
////	std::cout << *orig_it << std::endl;
//
////	std::cout << orig.front() << std::endl;
////	std::cout << my.front() << std::endl;
////
////	std::cout << orig.back() << std::endl;
////	std::cout << my.back() << std::endl;
////
////	std::cout << orig.front() << std::endl;
////	std::cout << my.front() << std::endl;
////
////	std::cout << orig.back() << std::endl;
////	std::cout << my.back() << std::endl;
////	while (1);e
////	std::cout << orig.max_size() << std::endl;
////	std::cout << my.get_lock() << std::endl;
//----------------constructors-------------------
//	ft::List<int> first;                                // empty list of ints
//	ft::List<int> second (4,100);                       // four ints with value 100
//	ft::List<int> third (second.begin(),second.end());  // iterating through second
//	ft::List<int> fourth (third);                       // a copy of third
//
//	// the iterator constructor can also be used to construct from arrays:
//	int myints[] = {16,2,77,29};
//	ft::List<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//
//	std::cout << "The contents of fifth are: ";
//	for (ft::List<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
//		std::cout << *it << ' ';
//	std::cout << '\n' << first.size() << std::endl;
//	std::cout << second.size() << std::endl;
//	std::cout << third.size() << std::endl;
//	std::cout << fourth.size() << std::endl;
//	std::cout << '\n';
//-----------------destruct--------------------
//	ft::List<int> first;
//	first.push_back(5);
//	first.push_back(10);
//	first.~List();
//----------------operator = --------------------
//	ft::List<int> first (3);      // list of 3 zero-initialized ints
//	ft::List<int> second (5);     // list of 5 zero-initialized ints
//
//	second = first;
//	first = ft::List<int>();
//
//	first.print_list();
//	std::cout << "Size of first: " << int (first.size()) << '\n';
//	second.print_list();
//	std::cout << "Size of second: " << int (second.size()) << '\n';

//---------------reverse_iterator--------------
//==============R_begin==================
//	ft::List<int> mylist;
//	for (int i=1; i<=5; ++i) mylist.push_back(i);
//
//	std::cout << "mylist backwards:";
//	for (ft::List<int>::reverse_iterator rit=mylist.rbegin(); rit != mylist.rend(); ++rit)
//		std::cout << ' ' << *rit;
//
//	std::cout << '\n';
//------------------max_size-------------------
//	unsigned int i;
//	ft::List<int> mylist;
//	std::list<int> mylist_1;
//
//	std::cout << mylist.max_size() << std::endl;
//	std::cout << mylist_1.max_size() << std::endl;

////-------------assign-------------
//	ft::List<int> first;
//	ft::List<int> second;
//
//	first.assign (7,100);                      // 7 ints with value 100
//
//	second.assign (first.begin(),first.end()); // a copy of first
//
//	int myints[]={1776,7,4};
//	first.assign (myints,myints+3);            // assigning from array
//
//	std::cout << "Size of first: " << int (first.size()) << '\n';
//	std::cout << "Size of second: " << int (second.size()) << '\n';
//	first.print_list();
//	second.print_list();
//
//	std::list<int> first_o;
//	std::list<int> second_o;
//
//	first_o.assign (7,100);                      // 7 ints with value 100
//
//	second_o.assign (first_o.begin(),first_o.end()); // a copy of first
//
//	int myints_o[]={1776,7,4};
//	first_o.assign (myints_o,myints_o+3);            // assigning from array
//
//	std::cout << "Size of first_o: " << int (first_o.size()) << '\n';
//	std::cout << "Size of second_o: " << int (second_o.size()) << '\n';
//	std::cout << "first_o contains:";
//	for (std::list<int>::iterator it=first_o.begin(); it!=first_o.end(); it++)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	std::cout << "second contains:";
//	for (std::list<int>::iterator it=second_o.begin(); it!=second_o.end(); it++)
//		std::cout << ' ' << *it;
//	std::cout << '\n';

//
////-------------insert----------------
//	ft::List<int> mylist;
//	ft::List<int>::iterator it;
//
//	// set some initial values:
//	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5
//
//	it = mylist.begin();
//	++it;       // it points now to number 2           ^
//
//	mylist.insert (it,10);                        // 1 10 2 3 4 5
//
//	// "it" still points to number 2                      ^
//	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
//
//	--it;       // it points now to the second 20            ^
//
//	std::vector<int> myvector (2,30);
//	mylist.insert (it,myvector.begin(),myvector.end());
//	// 1 10 20 30 30 20 2 3 4 5
//	//               ^
//	std::cout << "mylist contains:";
//	for (it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';

////--------------erase--------------
//	ft::List<int> mylist;
//	ft::List<int>::iterator it1,it2;
//
//	// set some values:
//	for (int i=1; i<10; ++i) mylist.push_back(i*10);
//
//	// 10 20 30 40 50 60 70 80 90
//	it1 = it2 = mylist.begin(); // ^^
//	advance (it2,6);            // ^                 ^
//	++it1;                      //    ^              ^
//
//	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
//	//    ^           ^
//
//	it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
//	//    ^           ^
//
//	++it1;                      //       ^        ^
//	--it2;                      //       ^     ^
//
//	mylist.erase (it1,it2);     // 10 30 60 80 90
//	//        ^
//
//	std::cout << "mylist contains:";
//	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
//		std::cout << ' ' << *it1;
//	std::cout << '\n';
//----------------swap-------------------
//	ft::List<int> first (3,100);   // three ints with a value of 100
//	ft::List<int> second (5,200);  // five ints with a value of 200
//
//	first.swap(second);
//
//	std::cout << "first contains:";
//	for (ft::List<int>::iterator it=first.begin(); it!=first.end(); it++)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	std::cout << "second contains:";
//	for (ft::List<int>::iterator it=second.begin(); it!=second.end(); it++)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
////--------------resize------------------
//	ft::List<int> mylis;
//
//	// set some initial content:
//	for (int i=1; i<10; ++i) mylis.push_back(i);
//
//	mylis.resize(5);
//	mylis.resize(8,100);
//	mylis.resize(12);
//
//	std::cout << "mylist contains:";
//	for (ft::List<int>::iterator it=mylis.begin(); it!=mylis.end(); ++it)
//		std::cout << ' ' << *it;
//
//	std::cout << '\n';
//-----------------------clear-----------------
//	ft::List<int> mylist;
//	ft::List<int>::iterator it;
//
//	mylist.push_back (100);
//	mylist.push_back (200);
//	mylist.push_back (300);
//
//	std::cout << "mylist contains:";
//	for (it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	mylist.clear();
//	mylist.push_back (1101);
//	mylist.push_back (2202);
//
//	std::cout << "mylist contains:";
//	for (it=mylist.begin(); it!=mylist.end(); ++it) {
//		std::cout << ' ' << *it;
//	}
//	std::cout << '\n';
//=======================splice=====================
//	ft::List<int> mylist1, mylist2;
//	ft::List<int>::iterator it;
//
//	// set some initial values:
//	for (int i=1; i<=4; ++i)
//		mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//	for (int i=1; i<=3; ++i)
//		mylist2.push_back(i*10);   // mylist2: 10 20 30
//
//	it = mylist1.begin();
//	++it;                         // points to 2
//
//	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
//	// mylist2 (empty)
//	// "it" still points to 2 (the 5th element)
//
//	mylist2.splice (mylist2.begin(),mylist1, it);
//	// mylist1: 1 10 20 30 3 4
//	// mylist2: 2
//	// "it" is now invalid.
//	it = mylist1.begin();
//	std::advance(it,3);           // "it" points now to 30
//
//	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//	// mylist1: 30 3 4 1 10 20
//
//	std::cout << "mylist1 contains:";
//	for (it=mylist1.begin(); it!=mylist1.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	std::cout << "mylist2 contains:";
//	for (it=mylist2.begin(); it!=mylist2.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//===================remove===============
//	int myints[]= {11,89,42,89,89,89,89,89,7};
//	ft::List<int> mylist (myints,myints+4);
//
//	mylist.remove(89);
//
//	std::cout << "mylist contains:";
//	for (ft::List<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	int _myints[]= {11,89,42,89,89,89,89,89,7};
//	std::list<int> _mylist (_myints,_myints+4);
//
//	_mylist.remove(89);
//
//	std::cout << "_mylist contains:";
//	for (std::list<int>::iterator it=_mylist.begin(); it!=_mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//=================remove_if=================
//	int myints[]= {15,36,7,17,20,39,4,1};
//	ft::List<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
//
//	mylist.remove_if (single_digit);           // 15 36 17 20 39
//
//	mylist.remove_if (is_odd());               // 36 20
//
//	std::cout << "mylist contains:";
//	for (ft::List<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//========================unique==================
//	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
//						 12.77, 73.35, 72.25, 15.3,  72.25 };
//	ft::List<double> mylist (mydoubles,mydoubles+10);
//
//	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77, 15.3, 72.25, 72.25, 73.0, 73.35
//	//
//
//	mylist.unique();           //  2.72,  3.14, 12.15, 12.77, 15.3, 72.25, 73.0, 73.35
//
//
//	mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
//	// 15.3,  72.25, 73.0
//
//	mylist.unique (is_near());           //  2.72, 12.15, 72.25
//
//	std::cout << "mylist contains:";
//	for (ft::List<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//========================reverse===========================
//	ft::List<int> mylist;
//
//	for (int i=1; i<10; ++i) mylist.push_back(i);
//
//	mylist.reverse();
//
//	std::cout << "mylist contains:";
//	for (ft::List<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//
//	std::cout << '\n';

//=====================_SWAP=====================
//	ft::List<int> foo (3,100);   // three ints with a value of 100
//	ft::List<int> bar (5,200);   // five ints with a value of 200
//
//	ft::swap(foo,bar);
//
//	std::cout << "foo contains:";
//	for (ft::List<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	std::cout << "bar contains:";
//	for (ft::List<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';

//=======================get_allocator===================
//	ft::List<int> mylist;
//	int * p;
//
//	// allocate an array of 5 elements using mylist's allocator:
//	p=mylist.get_allocator().allocate(5);
//
//	// assign some values to array
//	for (int i=0; i<5; ++i) p[i]=i;
//
//	std::cout << "The allocated array contains:";
//	for (int i=0; i<5; ++i) std::cout << ' ' << p[i];
//	std::cout << '\n';
//
//	mylist.get_allocator().deallocate(p,5);
//-------------------relational operators----------------
//	ft::List<int> a;
//	a.push_back(10);
//	a.push_back(20);
//	a.push_back(30);
//	ft::List<int> b;
//	b.push_back(10);
//	b.push_back(20);
//	b.push_back(30);
//	ft::List<int> c;
//	c.push_back(30);
//	c.push_back(20);
//	c.push_back(10);
//
//	if (a==b) std::cout << "a and b are equal\n";
//	if (b!=c) std::cout << "b and c are not equal\n";
//	if (!(a!=b)) std::cout << "a and b are equal\n"; 		//castom
//	if (b<c) std::cout << "b is less than c\n";
//	if (c>b) std::cout << "c is greater than b\n";
//	if (a<=b) std::cout << "a is less than or equal to b\n";
//	if (a>=b) std::cout << "a is greater than or equal to b\n";
//	std::cout << std::endl;
//	std::list<int> a_o;
//	a_o.push_back(10);
//	a_o.push_back(20);
//	a_o.push_back(30);
//	std::list<int> b_o;
//	b_o.push_back(10);
//	b_o.push_back(20);
//	b_o.push_back(30);
//	std::list<int> c_o;
//	c_o.push_back(30);
//	c_o.push_back(20);
//	c_o.push_back(10);
//
//	if (a_o==b_o) std::cout << "a_o and b_o are equal\n";
//	if (b_o!=c_o) std::cout << "b_o and c_o are not equal\n";
//	if (!(a_o!=b_o)) std::cout << "a_o and b_o are equal\n";
//	if (b_o<c_o) std::cout << "b_o is less than c_o\n";
//	if (c_o>b_o) std::cout << "c_o is greater than b_o\n";
//	if (a_o<=b_o) std::cout << "a_o is less than or equal to b_o\n";
//	if (a_o>=b_o) std::cout << "a_o is greater than or equal to b_o\n";}
//----------------merge----------------
//
//{
//	ft::list<double> first, second;
//
//	first.push_back(3.1);
//	first.push_back(2.2);
//	first.push_back(2.9);
//
//	second.push_back(3.7);
//	second.push_back(7.1);
//	second.push_back(1.4);
//
//	first.sort();
//	second.sort();
//
//
//	first.merge(second);
//
//	second.push_back(2.1);
//
//	for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	for (ft::list<double>::iterator it = second.begin(); it != second.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//
//
//	// (second is now empty)
//
//
//
//	first.merge(second, mycomparison);
//
//	std::cout << "m first contains:";
//	for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//}
//{
//	std::list<double> first, second;
//
//	first.push_back(3.1);
//	first.push_back(2.2);
//	first.push_back(2.9);
//
//	second.push_back(3.7);
//	second.push_back(7.1);
//	second.push_back(1.4);
//
//	first.sort();
//	second.sort();
//
//	first.merge(second);
//
//	second.push_back(2.1);
//
//	for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	for (std::list<double>::iterator it = second.begin(); it != second.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//
//	// (second is now empty)
//
//
//
//	first.merge(second, mycomparison);
//
//	std::cout << "o first contains:";
//	for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//}
//	--------------------sort-------------------
//	ft::list<int> mylist;
//	ft::list<int>::iterator it;
//
//	for (int i = 0; i < 50000; i++) {
//		mylist.push_back((int)rand() % 100000);
//	}
//
////	mylist.push_back (2);
//
//	std::cout << (7 / 2) << std::endl;
//	mylist.sort();
//
//	std::cout << "mylist contains:";
//	for (it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	mylist.sort(compare_nocase);
//
//	std::cout << "mylist contains:";
//	for (it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	ft::List<std::string> mylist;
//	ft::List<std::string>::iterator it;
//	mylist.push_back ("one");
//	mylist.push_back ("two");
//	mylist.push_back ("Three");
//
//	mylist.sort();
//
//	std::cout << "mylist contains:";
//	for (it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	mylist.sort(compare_nocase);
//
//	std::cout << "mylist contains:";
//	for (it=mylist.begin(); it!=mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';


//===================================================
//======================VECTOR=======================
//===================================================

//{
//====================push_back==============
//	ft::vector<int> myvector;
//	int myint;
//
//	std::cout << "Please enter some integers (enter 0 to end):\n";
//
//	do {
//		std::cin >> myint;
//		myvector.push_back (myint);
//	} while (myint);
//
//	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

//====================pop_back=====================
//	ft::vector<int> myvector;
//	int sum (0);
//	myvector.push_back (100);
//	myvector.push_back (200);
//	myvector.push_back (300);
//
//	while (!myvector.empty())
//	{
//		sum+=myvector.back();
//		myvector.pop_back();
//	}
//
//	std::cout << "The elements of myvector add up to " << sum << '\n';
//========================clear=======================
//	ft::vector<int> myvector;
//	myvector.push_back (100);
//	myvector.push_back (200);
//	myvector.push_back (300);
//
//	std::cout << "myvector contains:";
//	for (unsigned i=0; i<myvector.size(); i++)
//		std::cout << ' ' << myvector[i];
//	std::cout << '\n';
//
//	myvector.clear();
//	myvector.push_back (1101);
//	myvector.push_back (2202);
//
//	std::cout << "myvector contains:";
//	for (unsigned i=0; i<myvector.size(); i++)
//		std::cout << ' ' << myvector[i];
//	std::cout << '\n';
//=====================swap====================
//	ft::vector<int> foo (3,100);   // three ints with a value of 100
//	ft::vector<int> bar (5,200);   // five ints with a value of 200
//
//	foo.swap(bar);
//
//	std::cout << "foo contains:";
//	for (unsigned i=0; i<foo.size(); i++)
//		std::cout << ' ' << foo[i];
//	std::cout << '\n';
//
//	std::cout << "bar contains:";
//	for (unsigned i=0; i<bar.size(); i++)
//		std::cout << ' ' << bar[i];
//	std::cout << '\n';
//	std::vector<int> test;
//	test.push_back(5);
//	test.push_back(10);
//	test.push_back(115);
//	test.push_back(120);
//	test.push_back(125);
//	std::vector<int>::iterator it = test.begin();
//	std::vector<int>::iterator it_e = test.end();
//	std::vector<int>::const_iterator con_it = test.begin();
//
//	*con_it = 20;
//
//	std::cout << *con_it << " or test " << std::endl;
//
//	it += 2;
//
//	std::cout << it[1] << std::endl;
//	std::cout << (it < it_e) << std::endl;
//
//
//	ft::vector<int> my_test;
//	my_test.push_back(5);
//	my_test.push_back(10);
//	my_test.push_back(115);
//	my_test.push_back(120);
//	my_test.push_back(125);
//	ft::vector<int>::iterator my_it = my_test.begin();
//	ft::vector<int>::iterator my_it_e = my_test.end();
//	my_it += 2;
//
//	ft::vector<int>::const_iterator con_my_it = my_test.begin();
//
//	*con_my_it = 20;
//
//	std::cout << *con_my_it << " my const "<< std::endl;
//
//	std::cout << my_it[1] << std::endl;
//	std::cout << *my_it_e << std::endl;
//	std::cout << (my_it < my_it_e) << std::endl;
//======================insert===============
	
//	std::vector<int> test;
//	test.push_back(10);
//	test.push_back(20);
//	test.push_back(30);
//	test.push_back(40);
//
//	std::vector<int>::iterator it = test.begin() + 2;
//	std::vector<int>::iterator it_test;
//
//	std::cout << *it << std::endl;
//
//	it_test = test.insert(it, 111);
//
//	std::cout << *it_test << std::endl;
//
//	for (int i = 0; i < test.size(); ++i) {
//		std::cout << test[i] << " ";
//	}
	
//	ft::vector<int> myvector (3,100);
//	ft::vector<int>::iterator it;
//
//	it = myvector.begin();
//	it = myvector.insert ( it , 200 );
//
//	myvector.insert (it,2,300);
//
//	// "it" no longer valid, get a new one:
//	it = myvector.begin();
//
//	ft::vector<int> anothervector (2,400);
//	myvector.insert (it+2,anothervector.begin(),anothervector.end());
//
//	int myarray [] = { 501,502,503 };
//	myvector.insert (myvector.begin(), myarray, myarray+3);
//
//	std::cout << "myvector contains:";
//	for (it=myvector.begin(); it<myvector.end(); it++)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	myvector._print_vec();
//======================erase=========================
//{
//	std::vector<int> myvector;
//
//	// set some values (from 1 to 10)
//	for (int i=1; i<=10; i++) myvector.push_back(i);
//
//	// erase the 6th element
//	myvector.erase (myvector.begin()+5);
//
//	// erase the first 3 elements:
//	std::vector<int>::iterator it_test;
//
//	it_test = myvector.erase (myvector.begin(),myvector.begin()+3);
//
//	std::cout << *it_test << std::endl;
//	std::cout << "myvector contains:";
//	for (unsigned i=0; i<myvector.size(); ++i)
//		std::cout << ' ' << myvector[i];
//	std::cout << '\n';
//}
//
//{
//	ft::vector<int> myvector;
//
//	// set some values (from 1 to 10)
//	for (int i=1; i<=10; i++) myvector.push_back(i);
//
//	// erase the 6th element
//	myvector.erase (myvector.begin()+5);
//
//	// erase the first 3 elements:
//	ft::vector<int>::iterator it_test;
//
//	it_test = myvector.erase (myvector.begin(),myvector.begin()+3);
//
//	std::cout << *it_test << std::endl;
//
//	std::cout << "myvector contains:";
//	for (unsigned i=0; i<myvector.size(); ++i)
//		std::cout << ' ' << myvector[i];
//	std::cout << '\n';
//}
//======================assign==============
//	ft::vector<int> first;
//	ft::vector<int> second;
//	ft::vector<int> third;
//
//	first.assign (7,100);             // 7 ints with a value of 100
//
//	ft::vector<int>::iterator it;
//	it=first.begin()+1;
//
//	second.assign (it,first.end()-1); // the 5 central values of first
//
//	int myints[] = {1776,7,4};
//	third.assign (myints,myints+3);   // assigning from array.
//
//	std::cout << "Size of first: " << int (first.size()) << '\n';
//	std::cout << "Size of second: " << int (second.size()) << '\n';
//	std::cout << "Size of third: " << int (third.size()) << '\n';

//===========================Relational operators=======================
//	ft::vector<int> foo (3,100);   // three ints with a value of 100
//	ft::vector<int> bar (2,200);   // two ints with a value of 200
//
//	if (foo==bar) std::cout << "foo and bar are equal\n";
//	if (foo!=bar) std::cout << "foo and bar are not equal\n";
//	if (foo< bar) std::cout << "foo is less than bar\n";
//	if (foo> bar) std::cout << "foo is greater than bar\n";
//	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//======================max_size=======================
//	{
//		ft::vector<std::string> myvector;
//
//		// set some content in the vector:
//		for (int i = 0; i < 100; i++) myvector.push_back("a");
//
//		std::cout << "size: " << myvector.size() << "\n";
//		std::cout << "capacity: " << myvector.capacity() << "\n";
//		std::cout << "max_size: " << myvector.max_size() << "\n";
//	}
//
//	{
//		std::vector<std::string> myvector;
//
//		// set some content in the vector:
//		for (int i = 0; i < 100; i++) myvector.push_back("a");
//
//		std::cout << "size: " << myvector.size() << "\n";
//		std::cout << "capacity: " << myvector.capacity() << "\n";
//		std::cout << "max_size: " << myvector.max_size() << "\n";
//	}
//======================construct==================
//	ft::vector<int> first;                                // empty vector of ints
//	ft::vector<int> second (4,100);                       // four ints with value 100
//	ft::vector<int> third (second.begin(),second.end());  // iterating through second
//	ft::vector<int> fourth (third);                       // a copy of third
//
//	// the iterator constructor can also be used to construct from arrays:
//	int myints[] = {16,2,77,29};
//	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//
//	std::cout << "The contents of fifth are:";
//	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//===================resize====================
//	ft::vector<int>::size_type sz;
//
//	ft::vector<int> foo;
//	sz = foo.capacity();
//	std::cout << "making foo grow:\n";
//	for (int i=0; i<100; ++i) {
//		foo.push_back(i);
//		if (sz!=foo.capacity()) {
//			sz = foo.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//
//	ft::vector<int> bar;
//	sz = bar.capacity();
//	bar.reserve(100);   // this is the only difference with foo above
//	std::cout << "making bar grow:\n";
//	for (int i=0; i<100; ++i) {
//		bar.push_back(i);
//		if (sz!=bar.capacity()) {
//			sz = bar.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
	ft::vector<int> test(1025, 100);
	std::vector<int> std_test(1025, 100);
	test._print_vec();
	
	print_cont(std_test);
	return 0;
}
