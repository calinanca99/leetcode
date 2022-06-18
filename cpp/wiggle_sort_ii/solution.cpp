#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

void print_vec(const std::vector<int> &vec) {
  std::cout << '[' << ' ';
  for (const auto &elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << ']' << '\n';
}

void wiggleSort(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> nums_copy(n);

  std::sort(nums.begin(), nums.end());

  // Fill odd indexes
  int i = 1;
  int j = n - 1;
  while (i < n) {
    nums_copy[i] = nums[j];
    i += 2;
    --j;
  }

  // Fill even indexes
  i = 0;
  while (i < n) {
    nums_copy[i] = nums[j];
    i += 2;
    --j;
  }

  std::copy(nums_copy.begin(), nums_copy.end(), nums.begin());
}

int main() {
  std::vector<int> nums = {1, 5, 1, 1, 6, 4};
  wiggleSort(nums);
  print_vec(nums);

  std::cout << "----------------------------------------\n";

  nums = {1, 3, 2, 2, 3, 1};
  wiggleSort(nums);
  print_vec(nums);
}