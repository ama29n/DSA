#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Help {
	// Helper class 
	public:
	int maxi, mini, sum, isBst;
	Help() {
		maxi = -40000;
		mini = 40000;
		sum = 0;
		isBst = 1;
	}
};

// This will store the max sum for a BST
int ans = 0;

Help cal(TreeNode *root) {
	// Base Case
	if(!root) {
		Help h;
		return h;
	}
	Help l = cal(root->left), r = cal(root->right), h;
	
	// If either of the subtrees is not BST, subtree through current node will also not be a BST
	if(!l.isBst || !r.isBst) {
		h.isBst = 0;
		return h;
	}
	
	// Maintaining the sum
	h.sum += l.sum + r.sum + root->val;
	
	// Check for BST
	if(root->val > l.maxi && root->val < r.mini) {
		ans = max(ans, h.sum);
	} else {
		h.isBst = 0;
		return h;
	}
	
	// Maintaining the max and min for current node
	h.maxi = max({l.maxi, r.maxi, root->val});
	h.mini = min({l.mini, r.mini, root->val});
	return h;
}

int maxSumBST(TreeNode* root) {
	Help h = cal(root);
	return ans;
}