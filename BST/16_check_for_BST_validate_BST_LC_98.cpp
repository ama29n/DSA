#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left, *right;
};

// https://leetcode.com/problems/validate-binary-search-tree/

// Approach 1
class Solution {
public:
    typedef long long ll;
    class Help {
    public:
        bool isBST; ll smallest, largest;
        Help() {
            isBST = true; largest = LLONG_MIN; smallest = LLONG_MAX;
        }
    } def;
    Help dfs(TreeNode *root) {
        if(!root) {
            return def;
        }
        Help l = dfs(root->left), r = dfs(root->right), h;
        if(!l.isBST || !r.isBST) {
            h.isBST = false;
            return h;
        }
        if(root->val <= l.largest || root->val >= r.smallest) {
            h.isBST = false;
            return h;
        }
        h.smallest = min((ll)root->val, l.smallest);
        h.largest = max((ll)root->val, r.largest);
        return h;
    }
    bool isValidBST(TreeNode* root) {
        Help h = dfs(root);
        return h.isBST;
    }
};

// Approach 2
class Solution {
public:
    void in_order(TreeNode* root, vector<int> &v) {
        if(!root) {
            return;
        }
        in_order(root->left, v);
        v.push_back(root->val);
        in_order(root->right, v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        in_order(root, v);
        int n = v.size();
        if(n == 1) {
            return true;
        }
        for(int i = 1; i < n; i++) {
            if(v[i] <= v[i - 1]) {
                return false;
            }
        }
        return true;
    }
};