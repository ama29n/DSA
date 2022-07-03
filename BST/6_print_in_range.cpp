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
void inRange(TreeNode *root, int low, int up){
    if(!root) return;
    
    if(root->val > low && root->val > up) inRange(root->left, low, up);
    else if(root->val < low && root->val < up) inRange(root->right, low, up);
    else{
        inRange(root->left, low, up);
        cout<<root->val<<endl;
        inRange(root->right, low, up);
    }
}
int main()
{
    int n;
    cin >> n;
    TreeNode *root = takeInput();
    int low, up;
    cin>>low>>up;
    inRange(root, low, up);
    return 0;
}

// Input
// 21
// 50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
// 12
// 65

// Output
// 12
// 25
// 30
// 37
// 50
// 60
// 62