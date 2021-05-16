// setiosflags example
#include <iostream>     // std::cout, std::hex, std::endl
#include <iomanip>      // std::setiosflags

int main () {
  std::cout << std::hex;
  std::cout << std::setiosflags (std::ios::showbase)<<100<<std::endl;
  std::cout << std::setiosflags (std::ios::showbase | std::ios::uppercase);
  std::cout << 100 << std::endl;
  return 0;
}
