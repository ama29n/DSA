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

void level(node* &root)
{
    queue<node*> q;
    queue<node*> cq;
    q.push(root);
    
    while(q.size()>0)
    {
        node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        
        if(temp->left) cq.push(temp->left);
        if(temp->right) cq.push(temp->right);
        
        if(q.size()==0)
        {
            cout<<endl;
            while(cq.size()>0)
            {
                q.push(cq.front());
                cq.pop();
            }
        }
    }
}

int main()
{
    int size;

    cin >> size;

    node *root = takeInput();
    display(root);
    cout<<endl;
    level(root);
    return 0;
}