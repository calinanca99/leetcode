#include <cstddef>
#include <iostream>
#include <vector>

std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
  auto length = temperatures.size();
  std::vector<int> results;
  results.reserve(length);

  for (size_t i = 0; i < length; ++i) {
    auto counter = 1;
    for (size_t j = i + 1; j < length; ++j) {
      if (temperatures[j] > temperatures[i]) {
        results.push_back(counter);
        break;
      }

      if (j == length - 1) {
        results.push_back(0);
      }

      counter += 1;
    }
  }

  results.push_back(0);

  return results;
}

void print_vec(const std::vector<int> &vec) {
  std::cout << '[' << ' ';
  for (const auto &elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << ']' << '\n';
}

int main() {
  std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> output = dailyTemperatures(input);

  print_vec(input);
  print_vec(output);

  std::cout << "---------------------------------------\n";

  input = {30, 40, 50, 60};
  output = dailyTemperatures(input);

  print_vec(input);
  print_vec(output);

  std::cout << "---------------------------------------\n";

  input = {30, 60, 90};
  output = dailyTemperatures(input);

  print_vec(input);
  print_vec(output);
}