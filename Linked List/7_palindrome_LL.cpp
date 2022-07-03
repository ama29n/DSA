#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *reverse(ListNode *head)
  {
    ListNode *cur = head, *before = NULL, *after = NULL;
    while (cur != NULL)
    {
      after = cur->next;
      cur->next = before;
      before = cur;
      cur = after;
    }

    return before;
  }

  bool isPalindrome(ListNode *head)
  {

    if (head == NULL && head->next == NULL)
      return true;

    ListNode *slow = head, *fast = head, *ptr;
    while (fast->next != NULL && fast->next->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;

    ptr = head;

    while (slow != NULL)
    {
      if (ptr->val != slow->val)
        return false;
      ptr = ptr->next;
      slow = slow->next;
    }
    return true;
  }
};