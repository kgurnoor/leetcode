class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); //sort nums array
        int l = 0; //window l[ ]r
        int r = 0;
        int res = 0; //mmax windowlen
        long long total = 0; //sum of all numbers until nums[r]
        while(r < nums.size()){
            total+=nums[r]; //add elements of window into total
            //invalid window case
            while((long long)nums[r] * (r-l+1) > total + k){
                total = total - nums[l];
                l+=1; //reduce windowlen or shrink window
            }
            res = max(res, r-l+1);
            r+=1;
        }
        return res;
    }
};