#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
}*top;

void push(node* &top,int val)
{
    node *ptr=new node(val);
    if(top==NULL)
    {
        top=ptr;
        return;
    }
    ptr->next=top;
    top=ptr;
}

void display(node* &top)
{
    node* temp=top;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;}

}

void pop(node* &head)
{
    node *ptr=top;
    top=top->next;
    delete ptr;
}

int main()
{
    push(top,1);
    push(top,2);
    push(top,3);
    push(top,4);
    push(top,5);
    display(top);
    cout<<endl;
    pop(top);
    display(top);
}