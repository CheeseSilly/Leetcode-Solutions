struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    auto *cur = head;
    ListNode *pre = nullptr;
    while (cur) {
      auto temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;
  }
};