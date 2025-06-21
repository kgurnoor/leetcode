class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //created a hash map to hold [num, count]
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        //created a priority queue, to store elements in order of their priority , max heap = max count first
        priority_queue<pair<int, int>> maxHeap;
        for(auto& entry : freq){
            maxHeap.push({entry.second,entry.first});
        }
        //extracting k most frequent elements
        vector<int> result;
        for(int i = 0; i< k ; i++){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};