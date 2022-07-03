#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    vector<node*> child;

    node(int val)
    {
        data=val;
    }
};


void input(node *& root)
{
    int size;
    cin>>size;

    int *input=new int[size];

    for(int idx=0 ; idx<size ; idx++)
    cin>>input[idx];

    root=NULL;

    stack<node*> nodes;

    for(int idx=0 ; idx<size ; idx++)
    {
        if(input[idx]==-1)
        nodes.pop();

        else{

            node* new_node = new node(input[idx]);

            if(nodes.size()==0)
            root=new_node;

            else
            nodes.top()->child.push_back(new_node);

            nodes.push(new_node);
        }
    }
}



int main()
{
    node* root;
    input(root);
}



