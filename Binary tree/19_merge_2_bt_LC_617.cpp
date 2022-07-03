#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~node()
    {
        delete left;
        delete right;
    }
};

node *takeInput()
{
    static int index = 0;

    string rootData;

    cin >> rootData;

    if (rootData == "n")
    {
        return NULL;
    }

    node *root = new node(stoi(rootData));

    index++;

    root->left = takeInput();
    root->right = takeInput();

    return root;
}

void display(node* &root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

node* merge(node* a, node* b)
    {
        if(a==NULL && b==NULL)
            return NULL;
        
        if(!a)
            return b;
        if(!b)
            return a;
        
            node* temp=new node(0);
            temp->data+=a->data;
            temp->data+=b->data;
        
        temp->left=merge(a->left,b->left);
        
        temp->right=merge(a->right,b->right);
        
        return temp;
        
    }

int main()
{
    int size;
    cin >> size;

    node *root1 = takeInput();
    node *root2 = takeInput();

    node* newtree=(root1,root2);
    merge(root1,root2);
    
    return 0;
}




