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

node *reverse_k(node *&head, int k)
{
    if (!head)
        return NULL;

    node *cur = head, *after = NULL, *before = NULL;
    int count = 1;

    while (cur != NULL && count <= k)
    {
        after = cur->next;
        cur->next = before;
        before = cur;
        cur = after;
        count++;
    }

    head->next = reverse_k(after, k);

    return before;
}

int main()
{
    node *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    node *newnode = reverse_k(head, 5);
    display(newnode);
}