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

// we are given a binary tree of 0s and 1s and we have to delete all thode nodes which don't have a 1 in their children

// the idea is to do the question in post order and delete all those nodes which have value 0 along with the fact that they 
// don't have any children because if we consider a node having value 0 in between tree and it has left or right child
// then it is quite obvious that it has a 1 somewhere in its path which is why it doesn't has both of its children NULL


node* prune(node* &root)
{
    if(root==NULL)
    {
        return NULL;
    }

    root->left=prune(root->left);
    root->right=prune(root->right);

    if(root->data==0 && root->left == NULL && root->right== NULL)
    {
        return NULL;
    }

    return root;
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();

    node* newnode=prune(root);
    
    return 0;
}

