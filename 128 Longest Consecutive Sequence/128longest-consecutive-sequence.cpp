class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> set; //single copy (O(1) lookup of each element in array)
        int count = 0;
        int longest = 0;
        int start;
        for(int num:nums){
            set.insert(num);
        }
        for(auto it : set){
            //check if a number x exists whose x-1 does not exist in set - start of a sequence
            if(set.find(it - 1) == set.end()){ //count not find
                start = it;
                count = 1;
            }
            while(set.find(start + 1) != set.end()){
                start = start+1;
                count += 1;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};