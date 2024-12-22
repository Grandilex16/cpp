#include "atbash_cipher.h"
#include <cctype>

using namespace std;

namespace atbash_cipher {

string encode(string str) {

  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string reverseAlphabet = "zyxwvutsrqponmlkjihgfedcba";

  string out = "";
  int count = 0;
  unsigned long int strLen = str.length();

  for (unsigned long int i = 0; i < strLen; i++) {
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

  string out;
  unsigned long int strLen = str.length();

  for (unsigned long int i = 0; i < strLen; i++) {
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
} // namespace atbash_cipher
