/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

class Solution {
public:
  double x_n(double x, int n) {

    if (n == 0)
      return 1;
    if (x == 0)
      return 0;

    double res = x_n(x * x, n / 2);

    return (n % 2) ? res * x : res;
  }

  double myPow(double x, int n) {
    double res = x_n(x, n);

    return (n >= 0) ? res : 1 / res;
  }
};

#include <iostream>

int main() {

    double x = 3.14;
    int n = 7;

    Solution sol;

    std::cout << sol.myPow(x, n) << "\n";
}