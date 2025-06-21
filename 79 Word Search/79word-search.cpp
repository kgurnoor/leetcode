class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        function<bool(int, int, int)> dfs = [&](int top, int left, int index) -> bool {
            // base case: whole word matched
            if (index == word.length()) return true;

            // out of bounds or mismatch or already visited
            if (top < 0 || top >= rows || left < 0 || left >= cols || board[top][left] != word[index]) {
                return false;
            }

            char temp = board[top][left];
            board[top][left] = '#'; // mark visited

            // try all 4 directions
            bool found = dfs(top - 1, left, index + 1) ||  // up
                         dfs(top + 1, left, index + 1) ||  // down
                         dfs(top, left - 1, index + 1) ||  // left
                         dfs(top, left + 1, index + 1);    // right

            board[top][left] = temp; // backtrack
            return found;
        };

        for (int top = 0; top < rows; ++top) {
            for (int left = 0; left < cols; ++left) {
                if (dfs(top, left, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
