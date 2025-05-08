struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummynode = new ListNode(0);
    dummynode->next = head;
    ListNode *fast = dummynode, *slow = dummynode;
    for (int i = 0; i < n + 1; i++) {
      fast = fast->next;
    }
    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    ListNode *tmp = slow;
    slow->next = tmp->next->next;
    delete fast;
    return dummynode->next;
  }
};