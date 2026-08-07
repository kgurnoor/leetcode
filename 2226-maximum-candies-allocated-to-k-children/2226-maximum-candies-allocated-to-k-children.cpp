class Solution {
public:
    int bin_search(int low, int high, vector<int>& candies,long long k){
        int ans = 0;
        while(low <= high){
            long long sum = 0;
            int mid = low + (high-low)/2; //probable answer
            for(int i = 0; i < candies.size();i++){
                int group = candies[i]/mid;
                sum += group; //group = number of children
            }
            if(sum >= k){  //k > sum, possibility of answer is there, check for a bigger group size
                ans = mid; //remember this answer
                low = mid + 1;
            }
            else {
                high = mid - 1;//answer not found, mid is too big
            }
        }
        return ans;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int max_pile = *max_element(candies.begin(), candies.end());//find the element havin the max possibility of finding the group
        int ans = bin_search(1,max_pile,candies, k);
        return ans;
    }
};