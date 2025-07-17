class Solution {
public:
    int rows, cols;
    vector<vector<char>> earth;
    void dfs(int r, int c, vector<vector<bool>>& visited){
        //"vector<vector<bool>> visited" This creates a copy of visited every time, so changes are not reflected back. pass by reference 
        if (r < 0 || c < 0 || r >= rows || c >= cols){ //out of bounds
            return ;
        }
        if (visited[r][c]){ //already visited
            return;
        }
        if(earth[r][c] == '0'){ //earth[r][c] is of type char 
            return; //Return immediately, no marking needed.
        }
        //DFS is used to mark an entire island as visited so that we don’t count any part of it again. water i.e '0' is not land, so it is not visited
        visited[r][c] = true;
        //check all directions
        dfs(r+1,c,visited);
        dfs(r-1,c,visited);
        dfs(r,c+1,visited);
        dfs(r,c-1,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        earth = grid;
        int count = 0;
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited (rows, vector<bool> (cols, false));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j< cols; j++){
                // If it is land and unvisited, perform DFS to mark the entire island as visited.
                if(!visited[i][j] && earth[i][j] == '1'){
                    dfs(i,j,visited);
                    count++; //found an island 
                }
            }
        }
        return count;
    }
};