//
// Created by Retro Joella on 6/8/21.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP
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
	class map {
	public:
	
	private:
	
	public:
	};
#endif //FT_CONTAINERS_MAP_HPP
