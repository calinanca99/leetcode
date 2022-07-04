#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;

bool contains_duplicate(vector<int> &nums) {
  std::unordered_map<int, int> counter;
  for (const auto num : nums) {
    ++counter[num];

    if (counter[num] == 2) {
      return true;
    }
  }

  return false;
}

int main() {
  std::cout << "Test 1: \n";
  vector<int> nums = {1, 2, 3, 1};
  std::cout << "Result is: " << contains_duplicate(nums) << '\n';

  std::cout << "Test 2: \n";
  nums = {1, 2, 3, 4};
  std::cout << "Result is: " << contains_duplicate(nums) << '\n';

  std::cout << "Test 3: \n";
  nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  std::cout << "Result is: " << contains_duplicate(nums) << '\n';
}