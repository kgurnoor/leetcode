class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }
    bool isValid(TreeNode* node, long minval, long maxval){
        if(!node) return true; //all checks passed and reached leaf node
        if(node->val <= minval || node->val >= maxval){ //out of bounds
            return false;
        }
        return (isValid(node->left, minval, node->val) && isValid(node->right, node->val, maxval));
    }   
};
