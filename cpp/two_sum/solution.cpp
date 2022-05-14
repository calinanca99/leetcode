#include <iostream>
#include <vector>

using std::vector;

/*
    Given an array of integers nums and an integer target, return indices of the
   two numbers such that they add up to target. You may assume that each input
   would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
*/
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> indexes = {0, 0};

    int nums_len = nums.size();

    for (int i = 0; i < nums_len; i++) {
      int to_look_for = target - nums[i];
      for (int j = i + 1; j < nums_len; j++) {
        if (to_look_for == nums[j]) {
          indexes[0] = i;
          indexes[1] = j;
          return indexes;
        }
      }
    }
    return indexes;
  }
};

void print_vec(const vector<int> &vec) {
  for (auto const &elem : vec) {
    std::cout << elem << ", ";
  }
}

int main() {
  vector<int> nums = {3, 2, 4};
  int target = 6;

  Solution sol;

  vector<int> results = sol.twoSum(nums, target);
  print_vec(results);
}