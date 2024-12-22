#include "kindergarten_garden.h"
#include <array>
#include <cctype>
#include <vector>

using namespace std;

namespace kindergarten_garden {

array<Plants, 4> plants(string code_plant, string student) {

  int student_index = toupper(student[0]);
  student_index -= 65;

  unsigned long int plants_split = code_plant.find("\n");
  string first_plants = code_plant.substr(0, plants_split);
  string second_plants =
      code_plant.substr(plants_split + 1, code_plant.length() + 1);

  string stud_pl = first_plants.substr(student_index * 2, 2);
  stud_pl += second_plants.substr(student_index * 2, 2);

  vector<Plants> vec_plant;
  for (char b : stud_pl) {

    switch (b) {
    case 'V':
      vec_plant.emplace_back(Plants::violets);
      break;
    case 'R':
      vec_plant.emplace_back(Plants::radishes);
      break;
    case 'C':
      vec_plant.emplace_back(Plants::clover);
      break;
    case 'G':
      vec_plant.emplace_back(Plants::grass);
      break;
    default:
      break;
    }
  }
  // copying vec_plant to out{}

  array<Plants, 4> out = {};
  if (out.size() == vec_plant.size()) {
    for (long unsigned int i = 0; i < out.size(); i++) {
      swap(out[i], vec_plant[i]);
    }
  }

  return out;
}
} // namespace kindergarten_garden
