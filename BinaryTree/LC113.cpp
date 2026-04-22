class Solution {
public:
    // Push root->val in temp and accumulate sum at each node
    // At leaf, if sum == targetSum, save temp path to result
    // Pass temp by value so each branch has its own copy
    // Clear result before use to avoid dirty data
    vector<vector<int>> result;

    void helper(TreeNode* root, int targetSum, vector<int> temp = {}, int sum = 0) {
        if (root == nullptr) return;

        temp.push_back(root->val);
        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum)
                result.push_back(temp);
            return;
        }

        helper(root->left, targetSum, temp, sum);
        helper(root->right, targetSum, temp, sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        helper(root, targetSum);
        return result;
    }
};