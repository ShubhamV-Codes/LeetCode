class Solution {
public:
    // Accumulate path number at each node using ans = ans*10 + val
    // At leaf node, add formed number to globalSum
    // Clear globalSum before use to avoid dirty data
    int globalSum = 0;

    void helper(TreeNode* root, int ans = 0) {
        if (root == nullptr) return;

        ans = ans * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            globalSum += ans;
            return;
        }

        helper(root->left, ans);
        helper(root->right, ans);
    }

    int sumNumbers(TreeNode* root) {
        globalSum = 0;  // clear dirty data
        helper(root);
        return globalSum;
    }
};