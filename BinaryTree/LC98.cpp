class Solution {
public:
    bool ans = true;
    TreeNode* prev = nullptr;
    void helper(TreeNode* root) {
        if (root == nullptr)
            return;
        helper(root->left);
        if (prev == nullptr) {
            prev = root;
        } else if (root->val <= prev->val) {
            ans = false;
        }
        prev = root;
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};