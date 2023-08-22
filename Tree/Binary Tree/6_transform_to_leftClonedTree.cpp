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
    if(root->left)
    cout<<root->left->data<<" <- ";
    else cout<<". <- ";

    cout<<root->data;

    if(root->right)
    cout<<" -> "<<root->right->data;
    else cout<<" -> .";

    cout<<endl;

    if(root->left) display(root->left);
    if(root->right) display(root->right);
}

void leftClonedTree(node* &root)
{
    if(root->left) leftClonedTree(root->left);
    if(root->right) leftClonedTree(root->right);

    node* clone=new node(root->data);
    node* temp1=root->left;
    root->left=clone;
    clone->left=temp1;
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();
    
    leftClonedTree(root);
    display(root);
    return 0;
}

