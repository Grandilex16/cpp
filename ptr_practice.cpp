#include <cctype>
#include <iostream>

int main() {

  int a;
  int b;
  int *ptrA{&a};
  int *ptrB{&b};

  std::cout << "Plase press a number: ";
  std::cin >> a;
  std::cout << "please press another number: ";
  std::cin >> b;

  std::cout << *ptrA << "\n";
  std::cout << *ptrB << "\n";

  // Find the max of a integral data set
}
