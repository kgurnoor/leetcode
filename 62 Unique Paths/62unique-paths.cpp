class Solution {
public:
    //space optimisation
    int uniquePaths(int m, int n) {
        vector<int> dp_prevrow(n,0);
        for(int i = 0; i < m; i ++){
            vector<int> temp_currow(n,0);
            for(int j =0 ;j < n; j++){
                if(i == 0 && j == 0) temp_currow[j] = 1;
                else{
                    //dp[i][j] = dp[i-1][j] + dp[i][j-1] is our answer
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp_prevrow[j];
                    if(j>0) left = temp_currow[j-1];
                    temp_currow[j] = up+left ; 
                    }
                }
            dp_prevrow = temp_currow;
        }
        return dp_prevrow[n-1]; 
    }
};
