class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap : without sorting
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int num : nums){
            minheap.push(num);
            if(minheap.size() > k){
                minheap.pop(); //popping smaller elements until kth largest found from back
            }
        }
        return minheap.top();
    }
};