
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution {
public:
  
  int level(TreeNode* root, int ele, int h) // Function to calculate height of x and y
  {
    if( root == NULL )  return -1;
	
    if( root->val == ele ) return h;
    
    int ls=level(root->left,ele,h+1);
    if( ls > -1 ) return ls;
    int rs=level(root->right,ele,h+1);
    if( rs > -1 ) return rs;
    
    return -1;
  }
  
  bool check(TreeNode* root, int x, int y) // Function to check if x and y are cousins or not
  {
    if( root == NULL ) return true;
    
   if(root->left && root->right)
   {
      if( root->right->val == x && root->left->val == y ) return false;
      if( root->right->val == y && root->left->val == x ) return false;
   }
  
    bool ls=check(root->left,x,y);
    bool rs=check(root->right,x,y);
    
    if( ls == false || rs == false ) return false;
    return true;
  }
  
    bool isCousins(TreeNode* root, int x, int y) {
      
      int level1=level(root,x,0);
      int level2=level(root,y,0);
      if( level1 != level2 ) return false;
	  
      bool b=check(root,x,y);
      if( b == false ) return false;
      return true;
    }
};