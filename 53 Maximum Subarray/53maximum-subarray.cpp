class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int end = 0;
        int temp = 0;
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            if(sum > res){
                res = sum;
                start = temp;
                end = i;
            }
            if(sum < 0){
                sum = 0;
                temp = i+1;
            }
        }
        for(int i = start ; i <= end; i++){
            cout << nums[i] << ",";
        } 
        return res;
    }
};