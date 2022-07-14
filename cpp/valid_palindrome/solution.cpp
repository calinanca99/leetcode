#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using std::string;

bool is_palindrome(string s) {
  int left = 0;
  int right = s.length() - 1;

  while (left < right) {
    if (!std::isalnum(s[left])) {
      ++left;
    } else if (!std::isalnum(s[right])) {
      --right;
    } else if (std::tolower(s[left]) != std::tolower(s[right])) {
      return false;
    } else {
      ++left;
      --right;
    }
  }

  return true;
}

int main() {
  string s = {"A man, a plan, a canal: Panama"};
  std::cout << "Result is: " << is_palindrome(s) << '\n';
}