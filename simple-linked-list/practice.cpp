#include "simple_linked_list.cpp"
#include <iostream>

int main() {

  simple_linked_list::List empty{};
  empty.push(44);
  empty.push(54);

  std::cout << sizeof(empty) / sizeof(empty[0]);
  // std::cout << empty.size();
}
