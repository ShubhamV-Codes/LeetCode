class Solution {
public:
    // Logic: accumulate sum from root to leaf node
    // At leaf, check if sum == targetSum, return true if yes
    // Recurse both sides, if either returns true bubble it up
    // No global variable needed, bool return handles it cleanly
    bool helper(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr) return false;

        sum += root->val;

        if (root->left == nullptr && root->right == nullptr)
            return sum == targetSum;

        return helper(root->left, sum, targetSum) || 
               helper(root->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, 0, targetSum);
    }
};