#include "/home/jayce/cpp/troll-the-trolls/troll_the_trolls.cpp"
#include <cmath>
#include <ctime>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace hellmath;

// Darts practice
namespace darts {
int score(double point1, double point2) {
  int num = 0;
  if (pow(point1, 2) + pow(point2, 2) > 100) {
    num = 0;
  }
  if (pow(point1, 2) + pow(point2, 2) <= 100 &&
      pow(point1, 2) + pow(point2, 2) >= 25) {
    num = 1;
  }
  if (pow(point1, 2) + pow(point2, 2) <= 25 &&
      pow(point1, 2) + pow(point2, 2) >= 1) {
    num = 5;
  }
  if (pow(point1, 2) + pow(point2, 2) <= 1) {
    num = 10;
  }
  return num;
}
} // namespace darts

// Leap practice
namespace leap {
bool is_leap_year(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}
} // namespace leap

int main() {

  cout << boolalpha;

  // Coin Flip Demo
  srand(time(NULL));
  int coin = rand() % 8;

  // If number is 0: Heads
  // If it is not 0: Tails

  std::cout << coin;

  if (coin == 0) {

    std::cout << "Heads\n";

  } else {

    std::cout << "Tails\n";
  }
  std::cout << "\n\n";

  // Darts practice
  std::cout << "Got a score of: " << darts::score(-7.0, 7.0);
  std::cout << "\n\n";
  cout << "DARTS PRACTICE\n";
  cout << "----------------" << endl;
  cout << "Got a score of: " << darts::score(-7.0, 7.0);
  cout << "\n\n";

  // leap practice
  cout << "LEAP PRACTICE\n";
  cout << "----------------" << endl;
  if (leap::is_leap_year(1996) == 1) {
    cout << boolalpha << true;
  } else {
    cout << false;
  }
  cout << leap::is_leap_year(1996);
  if (leap::is_leap_year(1996) == 1) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
  // std::cout << leap::is_leap_year(1996);

  if (coin == 0) {
    cout << "Heads\n";
  } else {
    cout << "Tails\n";
  }

  // troll_the_trolls practice
  cout << "\n";
  cout << "TROLL THE TROLLS PRACTICE\n";
  cout << "--------------------------" << endl;

  cout << "Display Post: "
       << display_post(AccountStatus::troll, AccountStatus::troll) << endl;
  cout << "Permission Check: "
       << permission_check(Action::write, AccountStatus::mod) << endl;
  cout << "Valid Player Combination: "
       << valid_player_combination(AccountStatus::mod, AccountStatus::troll)
       << endl;
  cout << "has Priority: "
       << has_priority(AccountStatus::user, AccountStatus::mod) << endl;
}
