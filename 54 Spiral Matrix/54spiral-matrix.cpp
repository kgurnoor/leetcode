class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int left = 0 ;
        int top = 0 ;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;
        while(left <= right && top <= bottom ){
            //first go right
            for(int j = left; j <= right; j++){
                result.push_back(matrix[top][j]);
            }
            top++;
            //go down
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            //go left
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            //go up
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};