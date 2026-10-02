#include <iostream>
#include "yliu/vector.hpp"

int main()
{
  std::cout << "C++ data structure header only impl\n";

  yliu::vector<int> vec;
  std::cout << vec.size() << "\n";
  return 0;
}
