#include "mld.hpp"
#include "CustomClass.hpp"
#include "MemoryObjModel.hpp"
#include "cstring"
#include <cstdlib>
#include <list>
#include <string>
#undef new
#undef delete

std::vector<MemoryObj *> myAlloc;

void getInfo() {
  auto vecCurrent = myAlloc.begin();
  while (vecCurrent != myAlloc.end()) {

    getMemInfo((*vecCurrent));

    free((*vecCurrent)->ptr);
    free((*vecCurrent)->file);
    free((*vecCurrent)->function);
    free((*vecCurrent));
    vecCurrent++;
  }

  std::cout << "size " << myAlloc.size() << std::endl;
}

void operator delete(void *ptr) noexcept {
  for (auto &mem : myAlloc) {
    if (mem->ptr == ptr) {

      std::cout << "equal\n";
      free(mem->ptr);
      free(mem->file);
      free(mem->function);
      free(mem);
      myAlloc.erase(std::remove(myAlloc.begin(), myAlloc.end(), mem));
    }
  }
}

void *newImpl(std::size_t sz, char const *file, int line,
              char const *function) {
  void *ptr = std::malloc(sz);

  MemoryObj *memObj = (MemoryObj *)malloc(sizeof(MemoryObj));

  char *functionName = (char *)malloc(strlen(function) + 1);
  strncpy(functionName, function, strlen(function));
  char *fileName = (char *)malloc(strlen(file) + 1);
  strncpy(fileName, file, strlen(file));

  setValues(memObj, ptr, fileName, functionName, line);
  myAlloc.push_back(memObj);
  return ptr;
}
void *operator new[](size_t sz, char const *file, int line,
                     const char *function) {
  return newImpl(sz, file, line, function);
}

void *operator new(std::size_t sz, char const *file, int line,
                   const char *function) {
  return newImpl(sz, file, line, function);
}
