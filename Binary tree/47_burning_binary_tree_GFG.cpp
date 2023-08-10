#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution {
private:
    vector<int> ans;
    vector<Node *> findPath(Node *root, int node) {
        if(!root) return {};
        if(root->data == node) {
            return { root };
        }
        vector<Node *> l = findPath(root->left, node);
        vector<Node *> r = findPath(root->right, node);
        if(l.size() > 0) {
            l.push_back(root); return l;
        }
        if(r.size() > 0) {
            r.push_back(root); return r;
        }
        return {};
    }
    int dfs(Node *root, Node *after) {
        if(!root) return 0;
        int l = 0, r = 0;
        if(root->left && root->left != after) {
            l = dfs(root->left, after);
        }
        if(root->right && root->right != after) {
            r = dfs(root->right, after);
        }
        return max(l, r) + 1;
    }
 public:
    int minTime(Node* root, int target) {
        vector<Node *> path = findPath(root, target);
        int ans = 0;
        for(int i = 0; i < path.size(); i++) {
            int x = i + dfs(path[i], i == 0 ? NULL : path[i - 1]) - 1;
            ans = max(ans, x);
        }
        return ans;
    }
};