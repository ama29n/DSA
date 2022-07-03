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

// In case of even nodes, it will give the (n/2 + 1)th node.

void middle1(node *&head)
{
    node *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

// In case of even nodes, it will give the (n/2)th node.

void middle2(node *&head)
{
    node *fast = head, *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
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
    middle1(head);
}