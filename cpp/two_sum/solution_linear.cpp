#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
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
    /*
      Description of the solution:
      - define an `unordered_map` where the key is `nums[i]` and the value is
      `i` (where `i` is the index)
      - go through the `nums` and for every element compute `to_look_for =
      target - nums[i]`
      - if `to_look_for` is not in the map add `(nums[i], i)` to the map
      - when finding `to_look_for` in the map append `i` and `map[to_look_for]`
      to the results vec;
    */
    vector<int> indexes = {0, 0};
    unordered_map<int, int> value_index;

    for (int i = 0; i < nums.size(); i++) {
      int to_look_for = target - nums[i];

      if (value_index.count(to_look_for)) {
        indexes[0] = value_index[to_look_for];
        indexes[1] = i;
        return indexes;
      }

      value_index[nums[i]] = i;
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