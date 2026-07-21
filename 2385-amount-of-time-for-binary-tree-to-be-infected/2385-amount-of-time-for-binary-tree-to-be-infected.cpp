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
    int findmaxtime(map<TreeNode*, TreeNode*>& parentmap, TreeNode* target){
        //create a visited map for infected cells
        map<TreeNode*, int> visited;
        //create a q add, target in it
        queue <TreeNode*> q;
        q.push(target);
        visited[target] = 1; //target marked as visited
        int max_time = 0;
        while(!q.empty()){
            int sz = q.size();
            int flag = 0;
            for(int i = 0; i < sz; i++){ //at one time the q has a set of nodes that need to be traversed simultaneously, so just iterate through them together with for loop   
                TreeNode* node = q.front();
                q.pop(); //start iterating the current node
                //left exists and not infected yet
                if(node->left && !visited[node->left]){
                    flag = 1; //infected now
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                //right exists and not infected yet
                if(node->right && !visited[node->right]){
                    flag = 1; //infected now
                    visited[node->right] = 1;
                    q.push(node->right);
                }
                //top or parent exists and not visited yet
                if(parentmap[node] && !visited[parentmap[node]]){
                    flag = 1;
                    visited[parentmap[node]] = 1; 
                    q.push(parentmap[node]);
                }
            }
            //after iterating the simultaneous nodes, increase 1 unit of time
            if(flag) max_time++;
        }
        return max_time;
    }
    TreeNode* parentmapping(TreeNode* root, map<TreeNode*, TreeNode*>& parentmap, int start){
        queue<TreeNode*> q; 
        //add root to q
        q.push(root); 
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front(); //current node being iterated through
            if(node->val == start){
                res = node; //found the start node;
            }
            q.pop(); //remove from queue first
            if(node->left){ //if left child exists, add to queue for bfs traversal, map with parent
                q.push(node->left);
                parentmap[node->left] = node;
            }
            if(node->right){ //if right child exists, add to queue for bfs traversal, map with parent
                q.push(node->right);
                parentmap[node->right] = node;
            }      
        }
        return res; //now we have start node and the parentmap
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parentmap;
        TreeNode* target = parentmapping(root, parentmap, start); //need to find the start node address, and parent mapping hashmap created with bfs
        int max_time = findmaxtime(parentmap, target);
        return max_time;
    }
};