class Solution {
public:
    int trailingZeroes(int n) {
        int count = n/5;
        int numerator = count/5;
        while(numerator != 0){    
            count = count + numerator;
            numerator = numerator/5;
        }   
        return count; 
    }
};