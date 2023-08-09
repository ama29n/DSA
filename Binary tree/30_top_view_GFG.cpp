#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1 

class Solution {
private:
    #define ff first
    #define ss second
public:
    vector<int> topView(Node *root) {
        map<int, int> m;                 // < vertical, level, ele >
        queue<pair<Node *, int>> q;      // < node, vertical >
        q.push({ root, 0 });
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                Node *node = q.front().ff;
                int vertical = q.front().ss;
                q.pop();
                // If node is the first node to occupy this vertical 
                if(m.find(vertical) == m.end()) {
                    m[vertical] = node->data;
                }
                if(node->left) {
                    q.push({ node->left, vertical - 1 });
                }
                if(node->right) {
                    q.push({ node->right, vertical + 1 });
                }
            }
        }
        vector<int> ans;
        for(auto it : m) {
            ans.push_back(it.ss);
        }
        return ans;
    }
};