class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        int xorr = 0;
        for(int num:nums){
            xorr = xorr^num;
        }
        return xorr;
    }
};