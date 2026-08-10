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
        //bfs 
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination){
                return true;
            }
            for(int neighbour: adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};