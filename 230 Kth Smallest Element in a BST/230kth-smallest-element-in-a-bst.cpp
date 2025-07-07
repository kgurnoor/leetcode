/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;        // How many nodes have been visited so far
    int answer = -1;      // The kth smallest value to return

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k); // Perform inorder traversal with early stop
        return answer;
    }

    void inorder(TreeNode* root, int k) {
        if (!root || count >= k) return;

        inorder(root->left, k);     // Visit left subtree

        count++;                    // Visit current node
        if (count == k) {
            answer = root->val;     // Found kth node
            return;
        }

        inorder(root->right, k);    // Visit right subtree
    }
};
