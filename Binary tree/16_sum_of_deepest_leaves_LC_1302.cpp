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

    int sum=0;
    int height=INT_MIN;
    
    void sumL(node* &root, int level)
    {
        if(root==NULL)
            return;
        
        sumL(root->left,level+1);
        sumL(root->right,level+1);
        
        if(root->left==NULL && root->right==NULL)
        {
            if(level>height)
            {
                height=level;
                sum=0;
                sum+=root->data;
            }
            else if(level==height)
            {
                sum+=root->data;
            }
        }
        
    }

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();

    sumL(root,0);
    cout<<sum;
    
    return 0;
}

