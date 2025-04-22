/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
      return nullptr;
    }

    // head
    while (head != nullptr && head->val == val) {
      ListNode *tmp = head;
      head = head->next;
      delete tmp;
    }
    ListNode *ptr = head;
    while (ptr != nullptr && ptr->next != nullptr) {
      if (ptr->next->val == val) {
        ptr->next = ptr->next->next;
      } else {
        ptr = ptr->next;
      }
    }
    return head;
  }
};