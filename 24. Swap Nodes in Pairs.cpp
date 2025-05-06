struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *pre = dummyHead;
    ListNode *cur = head;
    ListNode *nxt = cur->next;

    while (cur != nullptr && nxt != nullptr) {
      ListNode *tmp = nxt->next;

      // 交换 cur 和 nxt
      nxt->next = cur;
      cur->next = tmp;
      pre->next = nxt;

      // 更新指针到下一组
      pre = cur;
      cur = cur->next;
      if (cur != nullptr)
        nxt = cur->next;
    }

    ListNode *res = dummyHead->next;
    return res;
  }
};

// Recursively

/**
 * class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* node1 = head;
        ListNode* node2 = head->next;
        ListNode* node3 = node2->next;

        node1->next = swapPairs(node3); // 1 指向递归返回的链表头
        node2->next = node1; // 2 指向 1

        return node2; // 返回交换后的链表头节点
    }
};
 */