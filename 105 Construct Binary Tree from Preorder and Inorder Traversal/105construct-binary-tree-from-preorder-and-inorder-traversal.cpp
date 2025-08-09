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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in inorder for quick lookup
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        int preorderIndex = 0;  // To track current root in preorder
        return build(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderIndexMap);
    }
private:
    // Helper function to build tree recursively
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int& preorderIndex, int left, int right,
                    unordered_map<int, int>& inorderIndexMap) {
        // Base case: if there are no elements to construct the tree
        if (left > right) return nullptr;
        // Get the current root value from preorder
        int rootValue = preorder[preorderIndex];
        preorderIndex++;  // Move to the next root in preorder
        // Create the root node
        TreeNode* root = new TreeNode(rootValue);
        // Find the index of this root value in the inorder array
        int inorderIndex = inorderIndexMap[rootValue];
        // Recursively build the left subtree
        root->left = build(preorder, inorder, preorderIndex, left, inorderIndex - 1, inorderIndexMap);
        // Recursively build the right subtree
        root->right = build(preorder, inorder, preorderIndex, inorderIndex + 1, right, inorderIndexMap);
        // Return the constructed subtree rooted at this node
        return root;
    }
};