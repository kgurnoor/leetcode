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
    int maxPathSum(TreeNode* root) {
        int result = root->val;

        // Define the recursive lambda function 
        // dfs is a recursive lambda that captures 'result' by reference

        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) return 0;

            // Recursively find max gain from left and right
            int leftMax = max(dfs(node->left), 0);  // ignore negative paths
            int rightMax = max(dfs(node->right), 0);

            // Update result if current split path is better
            result = max(result, node->val + leftMax + rightMax);

            // Return the best one-side path (cannot split)
            return node->val + max(leftMax, rightMax);
        };

        dfs(root);  // Start the DFS
        return result;
    }
};