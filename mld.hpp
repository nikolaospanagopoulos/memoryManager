// myNew5.hpp

#ifndef MY_NEW5
#define MY_NEW5

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <new>
#include <string>
#include <vector>

void *newImpl(std::size_t sz, char const *file, int line, char const *function);

void *operator new(std::size_t sz, char const *file, int line,
                   char const *function);

void *operator new[](std::size_t sz, char const *file, int line,
                     char const *function);

void getInfo();
#define new new (__FILE__, __LINE__, __FUNCTION__)
void operator delete(void *ptr) noexcept;

#define delete delete

#endif // MY_NEW5
