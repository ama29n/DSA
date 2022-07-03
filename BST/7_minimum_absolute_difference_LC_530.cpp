// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes 
// in the tree.

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

class Solution {
public:
  
  int ans = INT_MAX;
  TreeNode *prev = NULL;
  
  void minDif(TreeNode* root){
    if(root->left) minDif(root->left);
    if(prev) ans = min(ans, root->val - prev->val);
    prev = root;
    if(root->right) minDif(root->right);
  }
  
    int getMinimumDifference(TreeNode* root) {
      minDif(root);
      return ans;
    }
}; 