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

node *reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main()
{
    node *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    display(head);
    node *newhead = reverse(head);
    display(head);
}