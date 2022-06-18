#include <iostream>
#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
  auto n = temperatures.size();
  std::vector<int> results(n, 0);
  std::stack<int> st{};

  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
      st.pop();
    }

    if (!st.empty()) {
      results[i] = st.top() - i;
    }

    st.push(i);
  }

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