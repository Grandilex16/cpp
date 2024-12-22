#include "election_day.cpp"
#include <iostream>
#include <vector>

struct student {
  std::string name;
  int age;
  std::vector<std::string> subjects;
};

int main() {

  election::ElectionResult option1{"David", 11};
  election::ElectionResult option2{"Shaw", 12};
  election::ElectionResult option3{"Ripley", 79};
  election::ElectionResult option4{"Ripley", 79};
  std::vector<election::ElectionResult> final_count{option1, option2, option3,
                                                    option4};
  election::ElectionResult &winner = election::determine_result(final_count);

  std::cout << winner.name;

  return 0;
}
