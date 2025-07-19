class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[len] = true; // base case: empty string is always breakable
        for (int i = len - 1; i >= 0; i--) { // iterate backwards
            for (string word : wordDict) { // check each word in dictionary
                int wlen = word.size();
                if (i + wlen <= len && s.substr(i, wlen) == word) {
                    dp[i] = dp[i + wlen];
                }
                if (dp[i]) break; // no need to check further if true
            }
        }
        return dp[0]; // whether entire string can be broken
    }
};










