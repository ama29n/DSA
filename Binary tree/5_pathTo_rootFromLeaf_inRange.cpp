#include <bits/stdc++.h>
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

void display(node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

int low,high;

void rootFromLeaf(node *&root, int sum, vector<int> &ans)
{
    sum += root->data;
    ans.push_back(root->data);

    if (root->left)
    {
        rootFromLeaf(root->left, sum , ans);
    }

    if (root->right)
    {
        rootFromLeaf(root->right, sum , ans);
    }

    if ((root->left == NULL && root->right == NULL) && (sum >= low && sum <= high))
    {
        for(auto ch: ans)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    ans.pop_back();
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();

    cin>>low>>high;

    vector<int> answer;
    rootFromLeaf(root, 0, answer);

    return 0;
}


