#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;

        return helper(root1->left, root2->right) &&
               helper(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return helper(root->left, root->right);
    }
};

int main() {
    /*
        Example symmetric tree:
              1
            /   \
           2     2
          / \   / \
         3   4 4   3
    */

    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3))
    );

    Solution obj;
    if (obj.isSymmetric(root)) {
        cout << "Tree is symmetric\n";
    } else {
        cout << "Tree is NOT symmetric\n";
    }

    return 0;
}