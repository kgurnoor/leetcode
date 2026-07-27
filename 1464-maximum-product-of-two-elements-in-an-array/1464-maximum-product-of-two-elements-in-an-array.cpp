class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0;
        int second = 0;
        for(int i = 1; i < nums.size(); i++){
            if(first == second && nums[i] < nums[first]){
                second = i;
            } 
            else if(nums[i] > nums[first] && nums[first] >= nums[second]){
                second = first;
                first = i;
            }
            else if(nums[i] <= nums[first] && nums[i] > nums[second]){
                second = i;
            }
        }
        int res = (nums[first] - 1)*(nums[second] - 1);
        return res;
    }
};