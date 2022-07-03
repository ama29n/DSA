
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
};

vector<vector<int>> levelOrder(TreeNode* root) {

        if (!root) return {}; 

        queue<TreeNode*> q;
        q.push(root); 
        vector<vector<int>> out;
    	 
        while (!q.empty()) {
            
            int sz = q.size(); /* current queue size */
            vector<int> curr(sz); /* vector of size sz */
						
            for (int i = 0; i < sz; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                curr[i] = tmp->val;
				
				/* Add the left & right nodes to the queue in the loop. */
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            out.push_back(curr); /* once the level is done, push the vector to output vector. */
        }
        return out;
    }