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
  
  TreeNode *build(vector<int> &pre, vector<int> &in, int s1, int s2, int e1, int e2){
    
    if(s1 > e1 || s2 > e2) return NULL;
    
    TreeNode* root = new TreeNode(pre[s1]);
    
    int ele = pre[s1], idx;
    for(int i=s2 ; i<=e2; i++){
      if(in[i]==ele){
        idx=i;
        break;
      }
    }
    idx = idx;
    int size = idx -s2;
    
    root->left = build(pre, in, s1+1, s2, s1+size, idx-1);
    root->right = build(pre, in, s1+size+1, idx+1, e1, e2);
    return root;
  }
  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      TreeNode* newroot = build(preorder,inorder,0,0,preorder.size()-1,inorder.size()-1);
      return newroot;
    }
};