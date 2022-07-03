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

int minn=INT_MAX;
int maxx=INT_MIN;

void width(node* &root, int breadth)
{
    if(root==NULL)
    return;

    width(root->left,breadth-1);
    width(root->right,breadth+1);

    minn=min(minn,breadth);
    maxx=max(maxx,breadth);

}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();

    width(root,0);

    cout<<maxx-minn+1;
    
    return 0;
}

