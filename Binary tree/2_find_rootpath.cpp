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

bool findd=false;

vector<int> find_rootpath(node* &root, int t)
{

    if(root->data==t)
    {
        findd=true;
        vector<int> answer;
        answer.push_back(root->data);
        return answer;
    }

    if(root->left != NULL)
    {
        vector<int> check=find_rootpath(root->left,t);
        if(check.size()>0)
        {
            check.push_back(root->data);
            return check;
        }
    }

    if(root->right != NULL)
    {
        vector<int> check2=find_rootpath(root->right,t);
        if(check2.size()>0)
        {
            check2.push_back(root->data);
            return check2;
        }
    }

    vector<int> empty;
    return empty;
}

int main()
{
    int size;

    cin >> size;

    node *root = takeInput();

    int target;
    cin>> target;
    vector<int> answer= find_rootpath(root,target);

    if(findd==true)
    cout<<"True\n";
    else cout<<"false\n";

    for(auto ch: answer)
    {
        cout<<ch<<" ";
    }
    return 0;
}