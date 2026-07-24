class Solution {
public:
    vector<int> temp; //startiing index 1
    int climbStairs(int n) {
        temp = vector<int>(n+1,0);
        return climb(n);
    }
    int climb(int n){
        if(n==1 || n==2){
            return n; 
        }
        if(temp[n] != 0){
            return temp[n];
        }
        temp[n] = climb(n-1) + climb(n-2);
        return temp[n];
    }
};