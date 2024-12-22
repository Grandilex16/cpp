#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle {

enum flavor {
  equilateral,
  isosceles,
  scalene,
};

flavor kind(double num1, double num2, double num3);

}; // namespace triangle
#endif // TRIANGLE_H
