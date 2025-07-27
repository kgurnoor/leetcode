class Solution {
public:
    int f(int index, int endindex, vector<int>& nums, vector<int>& dp){
        if(index > endindex) return 0; 
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + f(index+2,endindex,nums,dp);
        int notpick = 0 + f(index+1,endindex,nums,dp);
        return dp[index] = max(pick, notpick); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //edge case 
        if(n==1) return nums[0];
        vector<int> dp1(n, -1), dp2(n, -1);
        int case1 = f(0, n - 2, nums, dp1); // Rob from 0 to n-2
        int case2 = f(1, n - 1, nums, dp2); // Rob from 1 to n-1
        return max(case1, case2);
    }
};