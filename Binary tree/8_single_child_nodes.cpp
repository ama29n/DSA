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

void singleChild(node* &root)
{
    if((root->left != NULL) && (root->right == NULL))
    cout<<root->left->data<<endl;
    else if((root->left == NULL) && (root->right != NULL))
    cout<<root->right->data<<endl;

    if(root->left) singleChild(root->left);
    if(root->right) singleChild(root->right);
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();
    singleChild(root);
    
    return 0;
}

