#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
}; 

void left(Node *root, vector<int> &v) {
    Node *node = root->left;
    while(node) {
        if(!node->right && !node->left)
            break;
        v.push_back(node->data);
        if(node->left)
            node = node->left;
        else
            node = node->right;
    }
}
void right(Node *root, stack<int> &s) {
    Node *node = root->right;
    while(node) {
        if(!node->right && !node->left)
            break;
        s.push(node->data);
        if(node->right)
            node = node->right;
        else 
            node = node->left;
    }
}
void bottom(Node *root, vector<int> &v) {
    if(!root)
        return;
    bottom(root->left, v);
    if(!root->left && !root->right)
        v.push_back(root->data);
    bottom(root->right, v);
}
vector<int> boundary(Node *root) {
    if(!root->left && !root->right)
        return {root->data};
    vector<int> v;
    v.push_back(root->data);
    left(root, v);
    bottom(root, v);
    stack<int> s;
    right(root, s);
    while(s.size()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}