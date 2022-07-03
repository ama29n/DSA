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

int tiltsum=0;

int tilt(node* &root)
{
    if(root==NULL)
    return 0;
    
    int ls=tilt(root->left);
    int rs=tilt(root->right);
    
    tiltsum+=(fabs(ls-rs));
    
    return (ls+rs+root->data);
}


int main()
{
    int size;
    cin >> size;

    node *root = takeInput();
    tilt(root);
    cout<<tiltsum;
    
    return 0;
}

