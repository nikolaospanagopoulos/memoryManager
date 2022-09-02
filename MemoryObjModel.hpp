
#include <stdio.h>

struct MemoryObj {
  void *ptr;
  char *file;
  char *function;
  int line;
};

typedef struct MemoryObj MemoryObj;
void setValues(MemoryObj *memory, void *address, char *filename,
               char *functionName, int lineNumber);

void getMemInfo(const MemoryObj *memory);
