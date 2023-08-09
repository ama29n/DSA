#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
TreeNode* buildTree() {
    string s;
    vector<string> input;
    while(cin >> s) {
        input.push_back(s);
    }
    // Empty Tree
    if(input.size() == 0 || input[0] == "N") {
        return NULL;
    }
    // Root
    TreeNode *root = new TreeNode(stoi(input[0]));

    queue<TreeNode *> q;
    q.push(root);

    // Starting from second element
    int i = 1;

    while(!q.empty()) {
        // If 
        if(input.size() == i) {
            return root;
        }

        // Node 
        TreeNode *node = q.front(); q.pop(); 

        // Left Node
        if(input[i] != "N") {
            TreeNode *l = new TreeNode(stoi(input[i]));
            node->left = l;
            q.push(l);
        }

        i++;

        if(i == input.size()) {
            return root;
        }

        // Right Node
        if(input[i] != "N") {
            TreeNode *r = new TreeNode(stoi(input[i]));
            node->right = r;
            q.push(r);
        }

        i++;
    }

    return root;
}

void dfs(TreeNode *root) {
    if(!root) return;
    cout << root->val << " ";
    dfs(root->left); dfs(root->right);
}

int main() {
    string s;
    cin >> s; 
    cout << s;
}

// 4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8 