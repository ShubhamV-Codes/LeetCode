class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        bool isnF = false;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                isnF = true;
            } else {
                if (isnF)
                    return false;

                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};