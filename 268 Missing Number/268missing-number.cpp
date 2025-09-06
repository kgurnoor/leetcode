class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        int xor_nums = 0;

        // XOR of 0..n
        for (int i = 0; i <= n; i++) {
            xor_all ^= i;
        }

        // XOR of elements in nums
        for (int num : nums) {
            xor_nums ^= num;
        }

        // Missing number is the difference
        return xor_all ^ xor_nums;
    }
};
