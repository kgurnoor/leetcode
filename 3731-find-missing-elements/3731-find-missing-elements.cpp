class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int current = nums[0]; //smalest
        vector<int> ans;
        for(int i = 0; i < n; i++){
            while(nums[i] > current){
                ans.push_back(current);
                current++;
            } 
            current = current + 1;
        }
        return ans;
    }
};