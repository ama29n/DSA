#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution when we need to rotate the list towards right side

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL)
            return NULL;

        int count = 1;
        ListNode *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            count++;
        }

        ptr->next = head;
        ptr = ptr->next;

        for (int i = 1; i < (count - (k % count)); i++) // In order to rotate towards right we need to do (count-k)
            ptr = ptr->next;

        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};

// When we want to rotate the list towards left side we don't need to maintain the count and we can just run the for loop
// till <k.