
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
      
      if(root1==NULL && root2==NULL)
          return true;
      if(root1==NULL && root2!=NULL)
        return false;
      if(root1!=NULL && root2==NULL)
        return false;
      if(root1->val != root2->val)
        return false;
      
      bool ls1=flipEquiv(root1->left,root2->right);
      bool rs1=flipEquiv(root1->right,root2->left);
      
      bool ls2=flipEquiv(root1->left,root2->left);
      bool rs2=flipEquiv(root1->right,root2->right);
      
      return (ls1 && rs1) || (ls2 && rs2);
      
    }
};