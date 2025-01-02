#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// making the grade practice

// Round down all provided student scores
std::vector<int> round_down_scores(std::vector<double> student_scores) {
  std::vector<int> roundedScores;
  for (double i : student_scores) {
    roundedScores.push_back(static_cast<int>(i));
  }
  return roundedScores;
}

// Count the number of failing students out of the group provided.
unsigned long int count_failed_students(std::vector<int> student_scores) {
  std::vector<int> failed;
  for (int i : student_scores) {
    if (i <= 40) {
      failed.push_back(i);
    }
  }
  return failed.size();
}

// Determine how many of the provided student scores were 'the best' based on
// the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores,
                                 int threshold) {
  std::vector<int> the_best{};
  for (int i : student_scores) {
    if (i >= threshold) {
      the_best.push_back(i);
    }
  }
  return the_best;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {

  double num1 = 0;
  double num2 = 0;
  double num3 = 0;
  double num4 = 41;

  num2 = ceil((highest_score + num4) / 2);
  num1 = ceil((highest_score + num2) / 2);
  num3 = (num2 + num4) / 2;

  std::array<int, 4> arr_scores{(int)num4, (int)num3, (int)num2, (int)num1};

  return arr_scores;
}

std::vector<std::string>
student_ranking(std::vector<int> student_scores,
                std::vector<std::string> student_names) {
  std::vector<std::string> tierList{};
  for (unsigned long int i = 0; i < student_names.size(); i++) {
    int num = 1;
    num += i;
    std::string rank1 = std::to_string(num) + ". " + student_names[i] + ": " +
                        std::to_string(student_scores[i]);
    tierList.emplace_back(rank1);
  }
  return tierList;
}

std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
  std::string valedictorian = "";
  for (unsigned long int i = 0; i < student_scores.size(); i++) {
    if (student_scores[i] == 100) {
      valedictorian = student_names[i];
    }
  }
  return valedictorian;
}

int main() {
  // Making the grade practice
  std::cout << "-=Making the Grade Practice=-\n\n";
  std::vector<int> student_scores{100, 99, 90, 84, 66, 53, 47};
  std::vector<std::string> student_names{"Joci",  "Sara", "Kora", "Jan",
                                         "Indra", "Bern", "Fred"};

  // Testing functions
  std::cout << "1. Rounded scores: ";
  for (int i : round_down_scores({5.2, 77.1, 91.0})) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  std::cout << "2. Non-Passing Students: ";
  std::cout << count_failed_students({40, 40, 35, 70, 30, 41, 90}) << "\n";

  std::cout << "3. The Best: ";
  int num = 65;
  for (int i : above_threshold(student_scores, num)) {
    std::cout << i << " ";
  }

  std::cout << "above_threshold: ";
  std::vector<int> thresScores{88, 29, 91, 64, 78, 43, 41, 77, 36, 50};
  int thresh = 80;
  for (int i : above_threshold(thresScores, thresh)) {
    std::cout << i << ",";
  }
  std::cout << "\n";

  std::cout << "4. Calculating Letter Grades: ";
  int highestScore = 100;
  for (int i : letter_grades(highestScore)) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  std::cout << "5. Matching Names to Scores: ";
  for (std::string i : student_ranking(student_scores, student_names)) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
