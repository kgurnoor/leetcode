class Solution {
public:
    //space optimised tabulation
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n+1,0) , curr(n+1,0) ; // 2 arrays with n+1 elements and all rows 0 
        //base case in iteration , still returning 0
        for(int j = 0; j <= n ; j++ ){ //prev for text2 elements , all 0 
            prev[j] = 0;
        }
        for(int i = 1 ; i <= m ; i++){
            for (int j = 1; j <= n; j++){
                if (text1[i-1] == text2[j-1]) { //character match
                    curr[j] = 1 + prev[j-1];
                } 
                else{ //character does not match
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
