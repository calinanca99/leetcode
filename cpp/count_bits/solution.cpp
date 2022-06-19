#include <bitset>
#include <iostream>
#include <type_traits>
#include <vector>

void print_vec(const std::vector<int> &vec) {
  std::cout << '[' << ' ';
  for (const auto &elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << ']' << '\n';
}

std::vector<int> count_bits(int n) {
  std::vector<int> result;
  result.reserve(n + 1);

  for (int i = 0; i <= n; ++i) {
    std::bitset<64> b(i);
    result.push_back(b.count());
  }

  return result;
}

int main() {
  auto input = 5;
  auto output = count_bits(input);

  print_vec(output);
}
