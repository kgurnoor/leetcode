class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1, INT_MAX); //array stores number of coins to make amount i
        for(int i = 0; i <= amount ; i ++){
            for(int coin : coins ){
                dp[0] = 0; //base case , to make amount 0 , we need 0 coins
                if(i-coin >= 0 && dp[i - coin] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};