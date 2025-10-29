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
  ListNode* reorderList(ListNode *head) {
    if (head->next == NULL) {
      return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = slow;
    while (fast && fast->next) {
      prev = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast) {
      prev = slow;
      slow = slow->next;
    }
    prev->next = NULL;

    ListNode* p1 = head;
    ListNode* p2 = reverse(slow);


    ListNode* temp = p1;
    while (p1 && p2) {
      temp = p1->next;
      p1->next = p2;
      p1 = temp;
      temp = p2->next;
      p2->next = p1;
      p2 = temp;
    }

    return head;
  }

private:
  ListNode* reverse(ListNode* head) {
    if (head->next == NULL) {
      return head;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    while (curr) {
      ListNode* temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }
};
