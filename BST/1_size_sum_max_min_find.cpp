#include<bits/stdc++.h>
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

int size(TreeNode* root){
    if(!root) return 0;
    int l = size(root->left);
    int r = size(root->right);
    return l+r+1;
}

int sum(TreeNode* root){
    if(!root) return 0;
    int l = sum(root->left);
    int r = sum(root->right);
    return l+r+root->val;
}

int max(TreeNode *root){
    if(!root) return 0;
    if(!root->left && !root->right) return root->val;
    int r = max(root->right);
    return r;
}

int min(TreeNode *root){
    if(!root) return 0;
    if(!root->left && !root->right) return root->val;
    int l = min(root->left);
    return l;
}

bool find(TreeNode* root, int ele){
    if(!root) return false;
    if(root->val == ele) return true;
    bool l = false, r = false;
    if(ele < root->val) l = find(root->left, ele);
    if(ele > root->val) r = find(root->right, ele);
    if(l || r) return true;
    return false;
}


int main()
{
    int n;
    cin >> n;
    TreeNode *root = takeInput();
    int ele;
    cin>>ele;
    
    int a = size(root);
    int b = sum(root);
    int c = max(root);
    int d = min(root);
    bool e = find(root, ele);
    
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e;
    return 0;
}

