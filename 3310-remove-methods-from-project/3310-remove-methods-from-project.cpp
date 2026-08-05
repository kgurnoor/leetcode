class Solution {
public:
    void dfs(int node, unordered_map <int, vector <int>>& invoke, vector <int> &vis){
        vis[node] = 1; //exploring node using recursion stack
        //explore the children of node
        for (auto &it : invoke[node]){ //all v invoked by u
            if(!vis[it]){
                dfs(it, invoke, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //directed graph with u -> v
        unordered_map <int, vector <int>> invoke; //adjacency list
        for(auto &it: invocations){
            int u = it[0];
            int v = it[1];
            invoke[u].push_back(v);
        }
        vector <int> vis(n, 0);
        dfs(k, invoke, vis);
        //visited has been populated with infected nodes now

        vector <int> ans;
        //to find nodes to return
        for(auto &it: invocations){
            int u = it[0];
            int v = it[1];
            if (!vis[u] && vis[v]){ //u hasnt been infected (not infected -> infected node - infected group cannot be removed - return all nodes as they are)
                for(int i = 0; i <n ; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])  //return non infected only
                ans.push_back(i);
        }
        return ans;
    }
};