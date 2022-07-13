#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

bool is_anagram(string s, string t) {
  std::unordered_map<char, int> s_counter;
  std::unordered_map<char, int> t_counter;

  for (const auto &ch_s : s) {
    ++s_counter[ch_s];
  }

  for (const auto &ch_t : t) {
    ++t_counter[ch_t];
  }

  return s_counter == t_counter;
}

int main() {
  std::cout << "Test 1: \n";
  string s = "anagram";
  string t = "nagaram";
  std::cout << "Result is: " << is_anagram(s, t) << '\n';

  std::cout << "Test 2: \n";
  s = "rat";
  t = "car";
  std::cout << "Result is: " << is_anagram(s, t) << '\n';
}