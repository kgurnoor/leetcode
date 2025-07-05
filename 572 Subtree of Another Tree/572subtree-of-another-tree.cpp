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
    //helper function to check if 2 trees are equal
    bool isSametree(TreeNode * s, TreeNode * t){
        if(!s && !t){return true;} //both are null
        if(!s || !t){return false;} //one is null and one is not
        if(s->val != t->val){return false;}//root value doesnt match
        return isSametree(s->left,t->left) && isSametree(s->right,t->right); //and of answers from left and right subtrees of both trees
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSametree(root,subRoot)){return true;} //if trees match completely
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};