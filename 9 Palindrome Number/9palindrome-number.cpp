class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int sign = x > 0 ? 1 : -1 ;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            // Check for overflow before actually multiplying or adding
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;
            rev = rev * 10 + digit;
        }
        return rev*sign;
    }
    bool isPalindrome(int x) {
        int revnum =  reverse(x);
        if(x == revnum) return true;
        return false;
    }
};