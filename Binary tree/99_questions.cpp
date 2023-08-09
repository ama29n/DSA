// Longest consecutive sequence in BT 
// https://www.geeksforgeeks.org/longest-consecutive-sequence-binary-tree/ 

int ans = 0;
void dfs(TreeNode *root, int prev, int count) {
    if(!root) {
        return;
    }
    if(root->val == prev + 1) {
        count++;
    } else {
        count = 1;
    }
    ans = max(ans, count);
    dfs(root->left, root->val, count); 
    dfs(root->right, root->val, count);
}
// 1 2 4 3 N 5 6 N N 7 -> 3
// 6 N 9 7 10 N N N 11 -> 3

// Maximum sum of nodes in Binary tree such that no two are adjacent
// https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/