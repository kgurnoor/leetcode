class Solution {
public:
    vector<int> lookupTable;
    int climbStairs(int n) {
        //fibbonacci series : memoization
        lookupTable = vector<int>(n + 1, 0);
        return climb(n);
    }
    int climb(int n){
        if(n == 1 || n==2){
            return n;
        }
        if(lookupTable[n] != 0){
            return lookupTable[n];
        }
        lookupTable[n] = climb(n-1) + climb(n-2);
        return lookupTable[n]; 
    }
};