class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <int> indegree(n+1, 0);
        vector <int> outdegree(n+1, 0);
        //indegree = people who trust you
        //outdegree = people you trust
        //both conditions necessary
        if(n == 1) return 1;
        for(auto edge: trust){
            int u = edge[0];
            int v = edge[1];
            indegree[v] = indegree[v] + 1;
            outdegree[u] = outdegree[v] + 1;
        }
        for(int i = 0; i <= n; i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};