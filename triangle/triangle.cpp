#include "triangle.h"
#include "test/catch.hpp"
#include <stdexcept>

namespace triangle {

flavor kind(double num1, double num2, double num3) {

  flavor out = flavor::isosceles;
  bool tru_tri =
      (num1 + num2 >= num3) && (num2 + num3 >= num1) && (num1 + num3 >= num2);

  bool tri_check = (num1 > 0) && (num2 > 0) && (num3 > 0);
  if (tru_tri && tri_check) {
    if (num1 == num2 && num2 == num3) {

      out = flavor::equilateral;
      return out;
    }
    if (num1 == num2 || num1 == num3 || num3 == num2) {

      out = flavor::isosceles;
      return out;
    }
    if (num1 != num2 && num2 != num3) {
      out = flavor::scalene;
      return out;
    }
  } else {
    throw std::domain_error("throwing an error");
  }

  return out;
}

}; // namespace triangle
