class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //vertical reversal
        int top = 0; 
        int bottom = matrix.size() - 1;
        while(top<bottom){
            for(int j = 0; j < matrix[0].size(); j++){
                int temp = matrix[top][j];
                matrix[top][j] = matrix[bottom][j];
                matrix[bottom][j] = temp;
            }
            top++;
            bottom--;
        }
        //transpose of matrix
        for(int i = 0; i <matrix.size() ; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};