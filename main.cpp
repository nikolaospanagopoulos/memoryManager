#include "mld.hpp"
#include <string>
#include <vector>
class Nikos {

public:
  std::string name;
};
int main() {

  // Nikos *nikos = new Nikos;

  int n = 5, i;

  // delete nikos;

  int *myArr = new int;
  delete myArr;

  std::vector<int *> ve{};

  ve.push_back(new int{5});

  getInfo();
}
