#include "allergies.h"
#include <unordered_set>

using namespace std;

namespace allergies {

allergy_test::allergy_test(int num) : score(num) {}

bool allergy_test::is_allergic_to(string allergen) {

  for (pair i : allergies_map) {
    return score & allergies_map[allergen];
  }
  return false;
}

unordered_set<string> allergy_test::get_allergies() {

  unordered_set<string> found_set;

  int num = score;
  while (num > 0) {
    for (auto pair : allergies_map) {
      if (pair.second & num) {
        if (pair.second < 256) {
          found_set.insert(pair.first);
        }
        num -= pair.second;
      }
    }
  }
  return found_set;
}
} // namespace allergies
