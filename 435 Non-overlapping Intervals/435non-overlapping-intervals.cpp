class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort according to end
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int n = intervals.size();
        if(n == 0){
            return 0;
        }
        int prev = 0 ;//index of last processed interval
        int count = 1 ; // no. of non overlapping intervals
        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i; 
                count++;
            }
        }
        return n-count;
    }
};