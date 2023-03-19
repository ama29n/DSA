#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
}; 

// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1 

class Solution {
public:
    vector<int> ans;
    void left(Node *root) {
        Node *ptr = root;
        while(ptr) {
            if(!ptr->left && !ptr->right) {
                break;
            }
            ans.push_back(ptr->data);
            if(ptr->left) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
    }
    void bottom(Node *root) {
        if(!root) {
            return;
        }
        bottom(root->left);
        if(!root->left && !root->right) {
            ans.push_back(root->data);
        }
        bottom(root->right);
    }
    void right(Node *root) {
        stack<int> s;
        Node *ptr = root;
        while(ptr) {
            if(!ptr->left && !ptr->right) {
                break;
            }
            s.push(ptr->data);
            if(ptr->right) {
                ptr = ptr->right;
            } else {
                ptr = ptr->left;
            }
        }
        while(!s.empty()) {
            ans.push_back(s.top()); s.pop();
        }
    }
    vector<int> boundary(Node *root) {
        if(!root->left && !root->right) {
            return {root->data};
        }
        ans.push_back(root->data);
        left(root->left);
        bottom(root);
        right(root->right);
        return ans;
    }
};