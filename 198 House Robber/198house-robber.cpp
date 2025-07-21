class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); //prev2 -> prev -> prev -> curr
        //base case
        int prev = nums[0]; //0th index 
        int prev2 = 0; //negative numbers
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2; //when i is not negative, we add i-2 term, if i becomes negative , nothing added 
            int nottake = 0 + prev; //when not taken, i-1 is added 
            int curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev; //we have to return n-2 
    }
};