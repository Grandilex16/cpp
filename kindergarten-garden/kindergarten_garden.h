#pragma once

#include <array>
#include <string>
namespace kindergarten_garden {

enum Plants {
  grass,
  violets,
  clover,
  radishes,
};

std::array<Plants, 4> plants(std::string plants, std::string student);
} // namespace kindergarten_garden
