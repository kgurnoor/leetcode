class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n); //size n
        vector<bool> visited(n, false);
        //adjacency list
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
            //as the graph is bidirectional
        }
        return dfs(source, destination, adj, visited);
    }
    bool dfs(int node, int destination, vector<vector<int>> &adj, vector<bool>& visited){
        if(node == destination){
            return true;
        }
        visited[node] = true;
        for(int neighbour: adj[node]){
            if(!visited[neighbour]){//hasnt been explored and isnt the destination so explore its neighbours
                if(dfs(neighbour, destination, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};