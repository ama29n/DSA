#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *BST(vector<int> &ans, int s, int e){
    if (s > e) return NULL;
    if (e == s){
        TreeNode *root = new TreeNode(ans[e]);
        return root;
    }
    else{
        int i = s + (e - s) / 2;
        TreeNode *root = new TreeNode(ans[i]);
        root->left = BST(ans, s, i - 1);
        root->right = BST(ans, i + 1, e);
        return root;
    }
}
TreeNode *sortedArrayToBST(vector<int> &nums){
    TreeNode *newroot = BST(nums, 0, nums.size() - 1);
    return newroot;
}

// Input
// [-10,-3,0,5,9]

// Output
// [0,-10,5,null,-3,null,9]

// [0,-3,9,-10,null,5] is also accepted.