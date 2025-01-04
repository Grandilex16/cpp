#include "lasagna_master.cpp"
#include "lasagna_master.h"
#include <iostream>

int main() {
  std::string letter_a = "a";
  std::cout << letter_a << "\n";
  std::vector<std::string> layers{
      "sauce",   "noodles",  "béchamel", "meat",    "mozzarella", "noodles",
      "ricotta", "eggplant", "béchamel", "noodles", "sauce",      "mozzarella",
  };

  std::cout << lasagna_master::preparationTime(layers, 1) << "\n";
}
