class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i = nums.size() -2; i >= 0; i--){ //breaking point found
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = nums.size() - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
        }

        // Step 3: reverse suffix
        reverse(nums.begin() + index + 1, nums.end());

    }
};
