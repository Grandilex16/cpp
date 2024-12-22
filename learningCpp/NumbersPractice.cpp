#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// CompoundInterest Practice
double annual_balance_update(double balance) {
  while (balance < 0) {
    return balance + (balance * .03213);
  }
  while (balance >= 0 && balance < 1000) {
    return balance + (balance * 0.005);
  }
  while (balance >= 1000 && balance < 5000) {
    return balance + (balance * .01621);
  }
  while (balance >= 5000) {
    return balance + (balance * .02475);
  }
  return balance;
}

int years_until_desired_balance(double balance, double target_balance) {
  double num = 0;
  while (target_balance > balance) {
    balance = annual_balance_update(balance);
    num++;
  }
  return num++;
}

// Needs to return 3025
int square_of_sum(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    sum += i;
  }
  return pow(sum, 2);
}

// Needs to return 385
int sum_of_squares(int num) {
  int total = 0;
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    total += 1;
    int numsqr = pow(total, 2);
    sum = sum + numsqr;
  }
  return sum;
}

int difference(int num) { return square_of_sum(num) - sum_of_squares(num); }

// Atabash Practice
// Encodes a string.
string encode(string str) {

  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string reverseAlphabet = "zyxwvutsrqponmlkjihgfedcba";

  string out = "";
  int count = 0;
  int str_len = str.length();

  for (int i = 0; i < str_len; i++) {

    char c = tolower(str[i]);
    if (alphabet.find(c) != alphabet.npos) {
      if (count % 5 == 0 && !isspace(str[i]) && !ispunct(str[i]) &&
          count != 0) {
        out += ' ';
      }
      out += reverseAlphabet[alphabet.find(c)];
      count++;
    } else if (isdigit(c)) {
      out += c;
      count++;
    }
  }
  return out;
}

string decode(string str) {

  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string reverseAlphabet = "zyxwvutsrqponmlkjihgfedcba";

  string out = "";
  int str_len = str.length();
  for (int i = 0; i < str_len; i++) {
    char c = str[i];
    if (reverseAlphabet.find(c) != reverseAlphabet.npos) {
      if (isspace(c)) {
        continue;
      }
      out += alphabet[reverseAlphabet.find(c)];
    } else if (isdigit(c)) {
      out += c;
    }
  }
  return out;
}

int main() {
  std::cout << years_until_desired_balance(200.75, 214.88) << std::endl;
  std::cout << std::endl;

  /* Find the difference between the square of the sum
  and the sum of the squares of the first N natural numbers. */
  int number = 5;
  int squared = square_of_sum(number);
  int sumofsquares = sum_of_squares(number);

  std::cout << squared << std::endl;
  std::cout << sumofsquares << std::endl;
  std::cout << difference(number) << endl;

  cout << endl;

  // Atbash practice
  cout << "Atbash practice: " << endl;

  string encodingNums = "Testing,1 2 3, testing.";
  string encoding = "The quick brown fox jumps over the lazy dog.";
  string decoding = "gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt";
  string decodeNums = "gvhgr mt123 gvhgr mt";

  cout << "Encoding\n";
  if (encode(encoding) == "gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt") {
    cout << "Success!\n" << encode(encoding) << endl;
  } else {
    cout << "FAILED\n" << encode(encoding) << endl;
  }
  cout << endl;
  cout << "Decoding\n";
  if (decode(decoding) == "thequickbrownfoxjumpsoverthelazydog") {
    cout << "Success!\n" << decode(decoding) << endl;
  } else {
    cout << "FAILED\n" << decode(decoding) << endl;
  }

  cout << endl;
  cout << "Decoding with Numbers\n";
  if (decode(decodeNums) == "testing123testing") {
    cout << "Success\n" << decode(decodeNums) << endl;
  } else {
    cout << "FAILED\n" << decode(decodeNums) << endl;
  }
}
