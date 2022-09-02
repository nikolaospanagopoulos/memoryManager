#pragma once

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
#define new new (__FILE__, __LINE__, __PRETTY_FUNCTION__)
void operator delete(void *ptr) noexcept;

#define delete delete
