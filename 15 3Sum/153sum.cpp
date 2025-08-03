#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int n = nums.size();
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for `i`
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;
            int target = 0;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicate `j` values
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicate `k` values
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                } 
                else if (sum > target) {
                    k--;  // Decrease `k` to reduce the sum
                } 
                else {
                    j++;  // Increase `j` to increase the sum
                }
            }
        }
        return result;  // Return all unique triplets
    }
};

// First Pointer (i): If nums[i] is the same as nums[i - 1], we have already considered it in a previous iteration.
// Second Pointer (j): If nums[j] is the same as nums[j + 1], it will form the same triplet.
// Third Pointer (k): If nums[k] is the same as nums[k - 1], it will form the same triplet.


// Sorted: [-4, -1, -1, 0, 1, 2]
// Step 2: Loop Execution
// First iteration (i = 0, nums[i] = -4)
// Finds triplets, moves j and k.
// Second iteration (i = 1, nums[i] = -1)
// Finds two valid triplets: [-1, -1, 2] and [-1, 0, 1].
// Third iteration (i = 2, nums[i] = -1)
// Skipped because nums[i] == nums[i - 1].