#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://leetcode.com/problems/linked-list-in-binary-tree/ 

class Solution {
private:
    bool dfs(ListNode *head, TreeNode *root) {
        if(!head) return true;
        if(head && !root) return false;
        if(head->val != root->val) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
public:
    bool isSubPath(ListNode *head, TreeNode *root) {
        if(!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};