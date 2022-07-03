#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_1 { // Find the Inorder of the Tree and then create a perfect tree. Space - O(no. of nodes), Time - O(no. of nodes)
public:
    TreeNode* makeTree(vector<int> &v, int beg, int end) {
        if(beg > end) return NULL;
        int mid = beg + (end - beg) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = makeTree(v, beg, mid - 1);
        root->right = makeTree(v, mid + 1, end);
        return root;
    }
    void inOrder(TreeNode* root, vector<int> &v) {
        if(!root) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        TreeNode *newRoot = makeTree(v, 0, v.size() - 1);
        return newRoot;
    }
};