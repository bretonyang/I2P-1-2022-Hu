bool dfs(struct TreeNode* node, int targetSum, int currentSum);

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (!root) {
        return false;
    }
    return dfs(root, targetSum - (root->val), 0);
}

bool dfs(struct TreeNode* node, int targetSum, int currentSum) {
    if (!node || currentSum == targetSum) {
        return currentSum == targetSum;
    }

    if (dfs(node->left, targetSum, currentSum + node->val)) {
        return true;
    }
    return dfs(node->right, targetSum, currentSum + node->val);
}
