#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/my-calendar-iii/description/ 

class MyCalendarThree {
public:
    // Implementation of Node
    class Node {
        public:
        int val, lazy;
        Node *left, *right;
        Node(int _val = 0) {
            val = _val; lazy = 0;
            left = right = NULL;
        }
    };
    // Data Members
    Node *root;
    int maxN, maxK;                 
    // Function to update the segment tree 
    void update(Node *root, int low, int high, int l, int r) {
        if(!root->left) {
            root->left = new Node();
        }
        if(!root->right) {
            root->right = new Node();
        }
        if(root->lazy) {
            root->val += root->lazy; 
            root->left->lazy += root->lazy; 
            root->right->lazy += root->lazy;
            root->lazy = 0;
        }
        if(low > r || high < l || low > high) {
            return;
        }
        if(low >= l && high <= r) {
            root->val += 1;
            root->left->lazy += 1; 
            root->right->lazy += 1;
            return;
        }
        int mid = low + (high - low) / 2;
        update(root->left, low, mid, l, r);
        update(root->right, mid + 1, high, l, r);
        root->val = max(root->left->val, root->right->val);
    }
    // Function to perform query on segment tree
    int query(Node *root, int low, int high, int l, int r) {
        if(!root->left) {
            root->left = new Node();
        }
        if(!root->right) {
            root->right = new Node();
        }
        if(root->lazy) {
            root->val += root->lazy; 
            root->left->lazy += root->lazy; 
            root->right->lazy += root->lazy;
            root->lazy = 0;
        }
        if(low > r || high < l || low > high) {
            return 0;
        }
        if(low >= l && high <= r) {
            return root->val;
        }
        int mid = low + (high - low) / 2;
        int left = query(root->left, low, mid, l, r);
        int right = query(root->right, mid + 1, high, l, r);
        return max(left, right);
    }
    // Given Fucntions to be completed
    MyCalendarThree() {
        root = new Node();
        maxN = 1E9 + 1;
        maxK = 0;
    }
    int book(int sT, int eT) {
        update(root, 0, maxN - 1, sT, eT - 1);
        int qr = query(root, 0, maxN - 1, sT, eT - 1);
        maxK = max(maxK, qr);
        return maxK;
    }
};