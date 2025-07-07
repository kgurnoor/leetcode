/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Ensure p is the smaller value
        if (p->val > q->val) swap(p, q);
        while (root) {
            if (q->val < root->val) {
                // Both nodes are in left subtree
                root = root->left;
            } else if (p->val > root->val) {
                // Both nodes are in right subtree
                root = root->right;
            } else {
                // Found the split point → this is the LCA
                return root;
            }
        }
        return nullptr; // Should never reach here in a valid BST
    }
};
