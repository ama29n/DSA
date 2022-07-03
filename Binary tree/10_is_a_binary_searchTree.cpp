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

int maxx=INT_MIN;

bool isBST(node* &root)
{
    if(root==NULL)
    {
        return true;
    }
    
    bool check1=isBST(root->left);
    if(check1==false)
    {
        return false;
    }

    if(root->data<maxx)
    {
        return false;
    }

    maxx=root->data;

    bool check2=isBST(root->right);
    if(check2==false)
    {
        return false;
    }

    return true;
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();

    bool check= isBST(root);

    if(check==true)
    cout<<"true";
    else cout<<"false";
    
    return 0;
}

