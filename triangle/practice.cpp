#include "triangle.cpp"
#include <iostream>

using namespace std;

int main() {

  int num1 = 2;
  int num2 = 2;
  int num3 = 2;

  triangle::flavor output = triangle::kind(num1, num2, num3);

  switch (output) {
  case triangle::flavor::scalene:
    cout << "scalene";
    break;
  case triangle::flavor::isosceles:
    cout << "isosceles";
    break;
  case triangle::flavor::equilateral:
    cout << "equilateral";
    break;
  default:
    cout << "failed";
    break;
  }

  cout << "\n";
  cout << triangle::flavor::equilateral;
  return 0;
}
