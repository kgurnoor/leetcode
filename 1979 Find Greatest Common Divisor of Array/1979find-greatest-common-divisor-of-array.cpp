class Solution {
public:
    //euclidean algo
    int gcd (int a, int b){
        //modulo based
        if(b==0) return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int smallest = nums[0];
        int largest = nums[n-1];
        return gcd(largest,smallest);
    }
};