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

class Solution
{
public:
    TreeNode *build(vector<int> pre, int s, int e){
        if (s > e) return NULL;

        TreeNode *root = new TreeNode(pre[s]);
        int idx;
        
        for (int i = s + 1; i <= e; i++){
            if (pre[i] > pre[s]){
                idx = i;
                break;
            }
        }
        root->left = build(pre, s + 1, idx - 1);
        root->right = build(pre, idx, e);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder){
        TreeNode *newroot = build(preorder, 0, preorder.size() - 1);
        return newroot;
    }
};


// Input
// [8,5,1,7,10,12]

// Output
// [8,5,10,1,7,null,12]