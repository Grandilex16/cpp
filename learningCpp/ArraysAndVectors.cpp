#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// making the grade practice

// Round down all provided student scores
vector<int> round_down_scores(vector<double> student_scores) {
  vector<int> roundedScores;
  for (int i : student_scores) {
    roundedScores.push_back(static_cast<int>(i));
  }
  return roundedScores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
  vector<int> failed;
  for (int i : student_scores) {
    if (i <= 40) {
      failed.push_back(i);
    }
  }
  return failed.size();
}

// Determine how many of the provided student scores were 'the best' based on
// the provided threshold.
vector<int> above_threshold(vector<int> student_scores, int threshold) {
  vector<int> the_best{};
  for (int i : student_scores) {
    if (i >= threshold) {
      the_best.push_back(i);
    }
  }
  return the_best;
}

// Create a list of grade thresholds based on the provided highest grade.
array<int, 4> letter_grades(int highest_score) {
  // add average of highest_score and 41 into vector, then average of that and
  // 100 into vector
  //
  /* test
  100, 86, 71, 56, 41
  97, 83, 69, 55, 41
  81, 71, 61, 51, 41
  */

  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int num4 = 41;

  num2 += ceil((highest_score + 41.0) / 2.0);
  num1 += ceil((highest_score + num2) / 2.0);
  num3 += (num2 + num4) / 2.0;

  array<int, 4> arr_scores{num4, num3, num2, num1};

  return arr_scores;
}

vector<string> student_ranking(vector<int> student_scores,
                               vector<string> student_names) {
  vector<string> tierList{};
  for (int i = 0; i < student_names.size(); i++) {
    int num = 1;
    num += i;
    string rank1 = to_string(num) + ". " + student_names[i] + ": " +
                   to_string(student_scores[i]);
    tierList.emplace_back(rank1);
  }
  return tierList;
}

string perfect_score(vector<int> student_scores, vector<string> student_names) {
  string valedictorian = "";
  for (int i = 0; i < student_scores.size(); i++) {
    if (student_scores[i] == 100) {
      valedictorian = student_names[i];
    }
  }
  return valedictorian;
}

int main() {
  // Making the grade practice
  cout << "-=Making the Grade Practice=-\n\n";
  array<double, 10> doubleScores{90.33, 40.5,  55.44, 70.05, 30.55,
                                 25.45, 80.45, 95.3,  38.7,  40.3};
  vector<int> student_scores{100, 99, 90, 84, 66, 53, 47};
  vector<string> student_names{"Joci",  "Sara", "Kora", "Jan",
                               "Indra", "Bern", "Fred"};

  // Testing functions
  cout << "1. Rounded scores: ";
  for (int i : round_down_scores({5.2, 77.1, 91.0})) {
    cout << i << " ";
  }
  cout << "\n";

  cout << "2. Non-Passing Students: ";
  cout << count_failed_students({40, 40, 35, 70, 30, 41, 90}) << "\n";

  cout << "3. The Best: ";
  int num = 65;
  for (int i : above_threshold(student_scores, num)) {
    cout << i << " ";
  }

  cout << "above_threshold: ";
  vector<int> thresScores{88, 29, 91, 64, 78, 43, 41, 77, 36, 50};
  int thresh = 80;
  for (int i : above_threshold(thresScores, thresh)) {
    cout << i << ",";
  }
  cout << "\n";

  cout << "4. Calculating Letter Grades: ";
  int highestScore = 100;
  for (int i : letter_grades(highestScore)) {
    cout << i << " ";
  }
  cout << "\n";

  cout << "5. Matching Names to Scores: ";
  for (string i : student_ranking(student_scores, student_names)) {
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}
