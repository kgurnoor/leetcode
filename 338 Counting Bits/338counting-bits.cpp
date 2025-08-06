class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1); // Creates a vector of size n+1 with all elements initialized to 0
        ans[0] = 0;
        for( int i = 1 ; i <= n ; i ++){
            ans[i] = ans[i >> 1] + (i & 1); // Using previous results (in binary representation) and counting the last bit
            // i = 5
            // i >> 1 = 2 (binary: 10), ans[2] = 1 (Only one 1 in 10)
            // i & 1 = 1 (Last bit of 101 is 1)
            // So, ans[5] = ans[2] + 1 = 1 + 1 = 2
        }
        return ans;
    }
};