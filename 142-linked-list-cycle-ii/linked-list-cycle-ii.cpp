using namespace std;
#include <iostream>

/*class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};*/

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) {
        break;
      }
    }
    if (!fast || !fast->next) {
        return NULL;
    }
    int i = 1;
    fast = fast->next;
    while (fast != slow) {
      i++;
      fast = fast->next;
    }
    fast = head;
    slow = head;
    while (i > 0) {
      i--;
      fast = fast->next;
    }
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    
    return slow;
  }
};
