#include "MemoryObjModel.hpp"
#include <stdlib.h>

void setValues(MemoryObj *memory, void *address, char *filename,
               char *functionName, int lineNumber) {

  memory->function = functionName;
  memory->file = filename;
  memory->line = lineNumber;
  memory->ptr = address;

  printf("setting value : %s,%s \n", memory->file, memory->function);
}

void getMemInfo(const MemoryObj *memory) {
  printf("the allocation happened at file: %s", memory->file);
}
