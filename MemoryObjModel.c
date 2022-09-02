#include "MemoryObjModel.h"
#include <stdlib.h>

void setValues(MemoryObj *memory, void *address, char *filename,
               char *functionName, int lineNumber) {

  memory->function = functionName;
  memory->file = filename;
  memory->line = lineNumber;
  memory->ptr = address;
}

void getMemInfo(const MemoryObj *memory) {
  printf("the leaked memory was allocated at file: %s, and at function: %s , "
         "and on line: %d \n",
         memory->file, memory->function, memory->line);
}
