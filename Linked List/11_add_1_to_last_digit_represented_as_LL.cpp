#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void push(node *&head, int val)
{
    node *ptr = new node(val);
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// o(n) time and O(n) space method

node *addOne_1(node *head)
{
    stack<node *> s;
    node *ptr = head;
    while (ptr != NULL)
    {
        s.push(ptr);
        ptr = ptr->next;
    }
    int carry = 1;
    while (s.size() > 1)
    {
        s.top()->data += carry;
        carry = s.top()->data / 10;
        s.top()->data = s.top()->data % 10;
        s.pop();
    }
    s.top()->data += carry;
    return head;
}

// o(n) time and O(1) space method

node *reverse(node *head)
{
    node *cur = head;
    node *before = NULL, *after = NULL;
    while (cur != NULL)
    {
        after = cur->next;
        cur->next = before;
        before = cur;
        cur = after;
    }

    head = before;
    return head;
}
node *addOne_2(node *head)
{
    head = reverse(head);
    node *ptr = head;
    int carry = 1;
    while (ptr->next != NULL)
    {
        int *val = &ptr->data;
        *val += carry;
        carry = *val / 10;
        *val = *val % 10;
        ptr = ptr->next;
    }
    ptr->data += carry;
    head = reverse(head);
    return head;
}

// However in both methods if for the 1st node we get a 2 digit number, we are not creating a new node i.e. splitting
// the 2 digits into seprate nodes.

int main()
{
    node *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 9);
}