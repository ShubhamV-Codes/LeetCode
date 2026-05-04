
class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* err1L = nullptr;
    TreeNode* err1R = nullptr;
    TreeNode* err2L = nullptr;
    TreeNode* err2R = nullptr;
    int err = 0;

    void helper(TreeNode* root) {
        if (root == nullptr)
            return;
        helper(root->left);
        if (prev == nullptr)
            prev = root;
        if (root->val < prev->val) {
            if (err == 0) {
                err1L = prev;
                err1R = root;
                err++;
            } else {
                err2L = prev;
                err2R = root;
                err++;
            }
        }
        prev = root;
        helper(root->right);
    }

    void recoverTree(TreeNode* root) {

        helper(root);
        if (err == 1) {
            swap(err1L->val, err1R->val);

        } else {
            swap(err1L->val, err2R->val);
        }
    }
};