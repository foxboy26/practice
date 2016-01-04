#include "leetcode.h"
using namespace std;

ListNode *partition(ListNode *head, int x) {
  // Note: The Solution object is instantiated only once and is reused by each test case.
  ListNode* smaller = NULL;
  ListNode* greater = NULL;
  ListNode* smallerHead = NULL;
  ListNode* greaterHead = NULL;
  for (ListNode* l = head; l != NULL; l = l->next) {
    if (l->val < x) {
      if (smallerHead == NULL) {
        smallerHead = new ListNode(l->val);
        smaller = smallerHead;
      } else {
        smaller->next = new ListNode(l->val);
        smaller = smaller->next;
      }
    } else {
      if (greaterHead == NULL) {
        greaterHead = new ListNode(l->val);
        greater = greaterHead;
      } else {
        greater->next = new ListNode(l->val);
        greater = greater->next;
      }
    }
  }
  printList(smallerHead);
  printList(greaterHead);
  // concat two lists
  if (smallerHead) {
    // smaller is not empty
    smaller->next = greaterHead;
  } else {
    smallerHead = greaterHead;
  }
  return smallerHead;
}

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(1);
  ListNode* res = partition(head, 0);
  printList(res);
  return 0;
}
