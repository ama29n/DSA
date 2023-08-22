#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left, *right;
};

// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

class Solution {
    public:
    void in_order(Node *root, vector<int> &v) {
        if(!root) {
            return;
        }
        in_order(root->left, v);
        v.push_back(root->data);
        in_order(root->right, v);
    }
    vector<int> merge(Node *r1, Node *r2) {
       vector<int> v1, v2, v3;
       in_order(r1, v1);
       in_order(r2, v2);
       int m = v1.size(), n = v2.size(), i = 0, j = 0;
       while(i < m && j < n) {
           if(v1[i] < v2[j]) {
                v3.push_back(v1[i++]);
           } else {
               v3.push_back(v2[j++]);
           }
       }
       while(i < m) {
           v3.push_back(v1[i++]);
       }
       while(j < n) {
           v3.push_back(v2[j++]);
       }
       return v3;
    }
};