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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both are null
        if(p == nullptr && q == nullptr){
            return true;
        }
        //one is null, one is not
        if(p == nullptr || q == nullptr){
            return false;
        }
        // Both non-null, check value and recurse on children
        if(p->val != q->val){
            return false;
        }
        //Recurse on left and right subtrees and return logical AND
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};