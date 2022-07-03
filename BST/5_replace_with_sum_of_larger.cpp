#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode *takeInput()
{
    static int index = 0;

    string rootval;

    cin >> rootval;

    if (rootval == "n")
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(stoi(rootval));

    index++;

    root->left = takeInput();
    root->right = takeInput();

    return root;
}

void display(TreeNode* root){
    if(!root) return;
    root->left ? cout<<root->left->val<<" <- " : cout<<". <- ";
    cout<<root->val;
    root->right ? cout<<" -> "<<root->right->val : cout<<" -> .";
    cout<<endl;
    display(root->left);
    display(root->right);
}

int sum = 0;

void replace(TreeNode* root){
    if(!root) return;
    replace(root->right);
    int s=root->val;
    root->val = sum;
    sum+=s;
    replace(root->left);
}

int main()
{
    int n;
    cin >> n;
    TreeNode *root = takeInput();
    replace(root);
    display(root);
    return 0;
}

// Input
// 15
// 50 25 12 n n 37 n n 75 62 n n 87 n n

// Output
// 311 <- 224 -> 87
// 336 <- 311 -> 274
// . <- 336 -> .
// . <- 274 -> .
// 162 <- 87 -> 0
// . <- 162 -> .
// . <- 0 -> .