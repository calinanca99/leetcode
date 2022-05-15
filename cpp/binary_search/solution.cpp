#include <iostream>
#include <vector>

/*
    Given an array of integers nums which is sorted in ascending order, and an
    integer target, write a function to search target in nums. If target exists,
    then return its index. Otherwise, return -1.
*/

using std::vector;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    if (nums[left] == target)
      return left;
    if (nums[right] == target) {
      return right;
    }

    while (left <= right) {
      int middle = (left + right) / 2;

      if (nums[middle] == target)
        return middle;

      if (nums[middle] < target)
        left = middle + 1;
      else
        right = middle - 1;
    }

    return -1;
  }
};

int main() {
  Solution sol;

  vector<int> vec_1 = {-1, 4, 10, 12};
  int target_1 = -1;
  std::cout << sol.search(vec_1, target_1) << '\n';

  vector<int> vec_2 = {-1, 4, 10, 12};
  int target_2 = 12;
  std::cout << sol.search(vec_1, target_2) << '\n';

  vector<int> vec_3 = {-1, 4, 10, 12};
  int target_3 = 4;
  std::cout << sol.search(vec_3, target_3) << '\n';

  vector<int> vec_4 = {-1, 4, 10, 12};
  int target_4 = 14;
  std::cout << sol.search(vec_4, target_4) << '\n';

  vector<int> vec_5 = {-1, 4, 10, 12, 17};
  int target_5 = 4;
  std::cout << sol.search(vec_5, target_5) << '\n';
}