#include <iostream>

int main() {

  int value;
  std::cin >> value;

  // even
  if (value == 2) {
    std::cout << "NO";
  } else if (value % 2 == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}
