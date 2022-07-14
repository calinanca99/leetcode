#include <iostream>
#include <stack>
#include <string>

using std::string;

bool is_valid(string s) {
  /*
      Description

      Iterate through `s` and at each char `c`:
      - check if `c` is either one of (, [, {, }, ], )
          * if it's an open bracket => add it to the stack
          * it it's a closing bracket => check top of stack;
            if they're opposite pop from stack, otherwise return
            `false`
      - s `is_valid` if the stack is empty
  */

  std::stack<char> sk;

  if (s.length() % 2 != 0) {
    return false;
  }

  for (const auto c : s) {
    if (c == '{' || c == '[' || c == '(') {
      sk.push(c);
    } else {

      if (sk.empty() && (c == '}' || c == ']' || c == ')')) {
        return false;
      }

      auto top = sk.top();
      if (top == '{' && c == '}') {
        sk.pop();
      } else if (top == '[' && c == ']') {
        sk.pop();
      } else if (top == '(' && c == ')') {
        sk.pop();
      } else {
        return false;
      }
    }
  }

  return sk.empty();
}

int main() {
  string test = "{[()]}";
  auto result = is_valid(test);
  std::cout << "Result is: " << result << '\n';

  test = "{[(]]}";
  result = is_valid(test);
  std::cout << "Result is: " << result << '\n';

  test = "";
  result = is_valid(test);
  std::cout << "Result is: " << result << '\n';

  test = "))";
  result = is_valid(test);
  std::cout << "Result is: " << result << '\n';

  test = "){";
  result = is_valid(test);
  std::cout << "Result is: " << result << '\n';
}