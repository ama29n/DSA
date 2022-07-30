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

TreeNode *takeInput() {
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

int lca(TreeNode* root, int a, int b) {
    if(a < root->val && b < root->val){
        return lca(root->left, a, b);
    }
    else if(a > root->val && b > root->val){
        return lca(root->right, a, b);
    }
    else return root->val;
}

int main() {
    int n;
    cin >> n;
    TreeNode *root = takeInput();
    int a, b;
    cin >> a >> b;
    int ans = lca(root, a, b);
    cout<< ans;

    return 0;
}

// Input
// 21
// 50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
// 12
// 30

// Output
// 25