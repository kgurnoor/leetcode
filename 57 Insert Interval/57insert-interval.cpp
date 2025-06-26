class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;
        //case 1 : no overlapping before merge intervals
        //compare ending point of intervals to starting point of newInterval
        while(i < n && newInterval[0] > intervals[i][1]){
            result.push_back(intervals[i]);
            i++;
        }
        //case 2 : overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0] ){//end of newInterval should be >= start of intervals[i] : overlapping 
        //updating newInterval
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
        } 
        result.push_back(newInterval); //putting newInterval after merging into its correct position 
        //case 3 : no overlapping of intervals after newinterval being merged
        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};