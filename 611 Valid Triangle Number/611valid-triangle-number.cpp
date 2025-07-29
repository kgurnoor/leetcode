class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int count = 0;
        for(int k = n-1; k >= 2; k--){ //loop keeps on changing the third parameter 
            int i = 0; 
            int j = k-1;
            while(i<j){
                if(nums[i] + nums[j] > nums[k]){
                    count += (j-i); //triplets depend on changing value of j, i and k are fixed in one loop in valid cond., so when a valid sol find, the triplets(or j values) before already satisfy the contraint. we need to count them together
                    j--;
                }
                else{
                    i++; //invalid triplet
                }
            }
        }
        return count;
    }
};