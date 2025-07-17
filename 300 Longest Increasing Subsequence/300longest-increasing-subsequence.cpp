class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //binary search
        vector<int> temp;
        temp.push_back(nums[0]); 
        int len = 1; //first element(any element technically) of nums starts the subsequence
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > temp.back()){ //last element of temp should be less than current element
                temp.push_back(nums[i]); //add to the pseudo subsequence
                len++;
            }
            else{ //element is smaller than last element of temp :  replacement/ binary search required
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i]; //replaced
            }
        }
        return len;

    }
};