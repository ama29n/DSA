#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

// Helper class 
class Help { 
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

Help cal(TreeNode* root) {
	// Base Case
	if(!root) {
		Help h;
		return h;
	}

	Help l = cal(root->left), r = cal(root->right), h;
	
	// If either of the subtrees is not BST, subtree through current node will also not be a BST
	// Also if current node is less than the maximum node of left subtree or greater 
	// than the minimum node of right subtree, it can't be a bst
	if(!l.isBst || !r.isBst || root->val <= l.maxi || root->val >= r.mini) {
		h.isBst = 0;
		return h;
	}
	
	// If a BST is formed through current node
	h.sum += l.sum + r.sum + root->val;
	ans = max(ans, h.sum);
	h.maxi = max({root->val, r.maxi, l.maxi});
	h.mini = min({root->val, l.mini, r.mini});

	return h;
}

int maxSumBST(TreeNode* root) {
	Help h = cal(root);
	return ans;
}