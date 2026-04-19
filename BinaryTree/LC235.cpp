/*
 * LeetCode 235 - Lowest Common Ancestor of a Binary Search Tree
 *
 * Approach : Use BST property to navigate in ONE direction only
 * Unlike normal BT, we don't need to search both sides
 *
 * BST Property:
 *   left  subtree → smaller values
 *   right subtree → larger  values
 *
 * LCA Condition:
 *   p->val <= root->val <= q->val → root is LCA
 *
 * Step 1 : always pass smaller node as p, larger as q
 * Step 2 : if root is null → return
 * Step 3 : if root is p or q → it is the LCA (other must be in its subtree)
 * Step 4 : if root < p → both nodes in right subtree → go right
 * Step 5 : if root > q → both nodes in left  subtree → go left
 * Step 6 : root is between p and q → root is LCA
 *
 * Time  : O(H) → H = height of tree
 * Space : O(H) → recursion stack
 */

class Solution {
public:
    void helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(root == nullptr) return;
        if(root == p || root == q){ ans = root; return; }

        if(root->val < p->val){
            helper(root->right, p, q, ans);
        }else if(root->val > q->val){
            helper(root->left,  p, q, ans);
        }else{
            ans = root; return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        if(p->val < q->val) helper(root, p, q, ans);
        else                helper(root, q, p, ans);
        return ans;
    }
};