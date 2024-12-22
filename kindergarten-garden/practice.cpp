#include "kindergarten_garden.cpp"
#include "kindergarten_garden.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;
using namespace kindergarten_garden;

int main() {

  // string plants = "RC\nGG";
  string plants = "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV";
  string student = "aarry";

  // using students name as index
  int student_index = toupper(student[0]);
  student_index -= 65;

  // Array to be returned
  // Grabbing index of '\n' and creating new string from that
  unsigned long int plants_split = plants.find("\n");
  // first section of string `plants`
  string first_plants = plants.substr(0, plants_split);
  // second section of string `plants`
  string second_plants = plants.substr(plants_split + 1, plants.length() + 1);

  // using student_index to return placement of plants
  string stud_pl = first_plants.substr(student_index * 2, 2);
  stud_pl += second_plants.substr(student_index * 2, 2);

  // vector to copy into out{}
  vector<Plants> vec_plant;
  for (char a : stud_pl) {

    switch (a) {
    case 'R':
      vec_plant.emplace_back(Plants::radishes);
      break;
    case 'C':
      vec_plant.emplace_back(Plants::clover);
      break;
    case 'G':
      vec_plant.emplace_back(Plants::grass);
      break;
    case 'V':
      vec_plant.emplace_back(Plants::violets);
      break;
    default:
      break;
    }
  }

  // copying vec_plant contents to out{}
  // Plants *out = vec_plant.data();
  array<Plants, 4> out = {};
  if (out.size() == vec_plant.size()) {
    for (long unsigned int i = 0; i < out.size(); i++) {
      swap(out[i], vec_plant[i]);
    }
  }

  cout << "printing out array: ";
  for (long unsigned int i = 0; i < out.size(); i++) {
    cout << out[i] << " ";
  }

  cout << "\n";
  cout << stud_pl;

  return 0;
}
