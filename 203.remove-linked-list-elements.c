/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val) {
  struct ListNode dummy = {0, head};
  struct ListNode *cur = &dummy;
  while (cur->next) {
    struct ListNode *nxt = cur->next;
    if (nxt->val == val) {
      cur->next = nxt->next;
      free(nxt);
    } else {
      cur = nxt;
    }
  }
  return dummy.next;
}
// @lc code=end
