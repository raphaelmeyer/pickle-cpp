#include <algorithm>
#include <iostream>

int main() {
  std::string line;
  while(std::getline(std::cin, line)) {
    std::reverse(line.begin(), line.end());
    std::cout << line << std::endl;
  }

  return 0;
}