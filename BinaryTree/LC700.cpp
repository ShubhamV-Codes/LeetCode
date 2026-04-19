/*
 * LeetCode 700 - Search in a Binary Search Tree
 *
 * Approach : Recursion using BST property
 * BST property → left subtree  has smaller values
 *              → right subtree has larger  values
 * So at each node we only go in ONE direction, pruning the other half
 *
 * Time  : O(H) → H = height of tree (O(logN) balanced, O(N) skewed)
 * Space : O(H) → recursion stack
 */

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val) return root;
        if(root->val > val){
            return searchBST(root->left,  val);
        } else {
            return searchBST(root->right, val);
        }
        return nullptr;
    }
};