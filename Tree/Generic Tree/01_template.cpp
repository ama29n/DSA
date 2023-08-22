#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode *> child;
    TreeNode(int val) {
        data = val;
    }
};

void input(TreeNode *&root) {
    int size;
    cin >> size;
    int *input = new int[size];
    for (int idx = 0; idx < size; idx++) {
        cin >> input[idx];
    }
    root = NULL;
    stack<TreeNode *> nodes;
    for (int idx = 0; idx < size; idx++) {
        if (input[idx] == -1) {
            nodes.pop();
        } else {
            TreeNode *new_node = new TreeNode(input[idx]);
            if (nodes.size() == 0) {
                root = new_node;
            }
            else {
                nodes.top()->child.push_back(new_node);
            }
            nodes.push(new_node);
        }
    }
}

int main() {
    TreeNode *root;
    input(root);
}
