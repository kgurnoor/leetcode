class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0; //invalid 
        int prev1 = 1 ; //for dp[0] = 1
        int prev = 1 ; //for dp[1] = 1 , First character is valid (non-zero) 
        for (int i = 2; i <= n; i++) {
            // Check single digit (s[i-1])
            int curr = 0; //initialization of dp
            if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                curr += prev;
            }
            // Check two-digit number (s[i-2]s[i-1])
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                curr += prev1;
            }
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};