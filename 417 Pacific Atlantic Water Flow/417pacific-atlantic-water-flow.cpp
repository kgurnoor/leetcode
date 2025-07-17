class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> heights;
    void dfs(int r, int c, vector<vector<bool>>& visit, int prevHeight) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS) //out of bounds
            return;
        if (visit[r][c]) //already visited
            return;
        if (heights[r][c] < prevHeight) //we are looking for greater height now
            return;
        visit[r][c] = true;
        dfs(r + 1, c, visit, heights[r][c]);
        dfs(r - 1, c, visit, heights[r][c]);
        dfs(r, c + 1, visit, heights[r][c]);
        dfs(r, c - 1, visit, heights[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& inputHeights) {
        heights = inputHeights; // assign to class member
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        vector<vector<int>> res;
        for (int c = 0; c < COLS; c++) { 
            dfs(0, c, pac, heights[0][c]); //row 1 (on pacific side)
            dfs(ROWS - 1, c, atl, heights[ROWS - 1][c]);//last row (on atlantic side)
        }
        for (int r = 0; r < ROWS; r++) { 
            dfs(r, 0, pac, heights[r][0]); //column 1 on pacific side
            dfs(r, COLS - 1, atl, heights[r][COLS - 1]); //last column on atlantic side
        }
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c]) //common ones out 
                    res.push_back({r, c});
            }
        }
        return res;
    }
};
