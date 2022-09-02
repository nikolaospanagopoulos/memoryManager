#include <cstdlib>
#include <iostream>

class Nikos {

  int *n{};

public:
  Nikos() { n = new int; }
  ~Nikos() {
    std::cout << "nikol;is";

    free(n);
  }
};
