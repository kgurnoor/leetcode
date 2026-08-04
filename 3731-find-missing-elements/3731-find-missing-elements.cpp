class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        //returns an iterator pointing to minimum. 
        int mn = *min_element(nums.begin(), nums.end());
        //The * dereferences the iterator, giving the actual value.
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());
         //the set contains 
            // {
            // 1,
            // 4,
            // 5,
            // 7
            // }
        //Searching in an unordered_set: takes 0(1) time
        //s.count(6) -> returns 1 if exists and 0 if it doesnt
        for(int i = mn+1 ; i < mx; i++){ //between mn and mx
            if(!s.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};