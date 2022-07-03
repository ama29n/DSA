#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode(){
        delete left;
        delete right;
    }
};

TreeNode *takeInput(){
    static int index = 0;

    string rootval;

    cin >> rootval;

    if (rootval == "n"){
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

TreeNode* add(TreeNode* root, int ele){
    if(!root){
        TreeNode* ptr = new TreeNode(ele);
        return ptr;
    }
    if(ele < root->val) root->left = add(root->left, ele);
    if(ele > root->val) root->right = add(root->right, ele);
    return root;
}

int main()
{
    int n;
    cin >> n;
    TreeNode *root = takeInput();
    int ele;
    cin>>ele;
    add(root, ele);
    display(root);
    return 0;
}


