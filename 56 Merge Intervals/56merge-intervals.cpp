class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());
       
        // Step 2: Create a result vector to store merged intervals
        vector<vector<int>> result;

        // Step 3: Go through each interval
        for (auto interval : intervals) {
            // If result is empty or current interval does not overlap
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval); // just add the interval
            } else {
                // If it overlaps, merge with the last interval in result
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};