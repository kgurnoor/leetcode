/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string using preorder traversal.
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }

private:
    // Helper function to build tree from stream
    TreeNode* buildTree(stringstream& ss) {
        string token;
        getline(ss, token, ',');

        if (token == "N") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
        return node;
    }
};
