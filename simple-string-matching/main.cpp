#include <ios>
#include <iostream>

bool solve(std::string a, std::string b) {
  // start from char before * and after * and use b to fill in rest
  if (a == b) {
    return true;
  } else {
    if (a.find('*') != std::string::npos) {
      unsigned long int ast_index = a.find('*');
      char char_stop = a[ast_index + 1];
      unsigned long stop_index = b.find(char_stop);
      stop_index = stop_index - ast_index;

      std::string found = b.substr(ast_index, stop_index);
      a.insert(ast_index, found);
      a.erase(a.begin() + (ast_index + found.length()));
      // someones solution, needs to be studied.
      std::cout << (b.find(a.substr(0, a.find("*"))) != std::string::npos) &&
          (b.find(a.substr(a.find("*") + 1)) != std::string::npos);

      if (a == b) {
        return true;
      }
    } else {
      return false;
    }

    return false;
  }
}

int main() {
  std::cout << "solving the problem!" << "\n";
  std::cout << std::boolalpha << solve("codewar*s", "codewars") << "\n";
}
