#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(const ListNode *head) {
  auto curr = head;

  std::cout << "[ ";
  while (curr != nullptr) {
    std::cout << " " << curr->val << " ";
    curr = curr->next;
  }
  std::cout << " ]\n";
}

class Solution {
public:
  int get_size(ListNode *head) {
    auto length = 0;
    auto curr = head;
    while (curr != nullptr) {
      length += 1;
      curr = curr->next;
    }

    return length;
  }

  ListNode *get_tail(ListNode *head) {
    auto curr = head;
    for (;;) {
      if (curr->next == nullptr) {
        return curr;
      } else {
        curr = curr->next;
      }
    }
  }

  ListNode *get_before_tail(ListNode *head) {
    auto curr = head;
    auto tail = get_tail(head);
    for (;;) {
      if (curr->next == tail) {
        return curr;
      } else {
        curr = curr->next;
      }
    }
  }

  ListNode *rotate_right(ListNode *head, int k) {
    for (int i = 0; i < k; ++i) {
      auto tail = get_tail(head);
      auto before_tail = get_before_tail(head);

      before_tail->next = nullptr;
      tail->next = head;
      head = tail;
    }

    return head;
  }
};

int main() {
  Solution sol;

  auto last = ListNode(4);
  auto second = ListNode(3, &last);
  auto first = ListNode(2, &second);
  auto head = ListNode(1, &first);

  std::cout << "List has length: " << sol.get_size(&head) << '\n';

  std::cout << "Before rotate: \n";
  print_list(&head);

  auto after_head = sol.rotate_right(&head, 5);

  std::cout << "After rotate: \n";
  print_list(after_head);
}