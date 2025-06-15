class Solution {
public:
    int countSubstrings(string s) {
        int count = 0; 
        for ( int i = 0 ; i < s.size() ; i ++ ){
            //for odd length palindromes
            int left1 = i;
            int right1 = i;
            while(left1>=0 && right1 < s.size() && s[left1] == s[right1]){
                count++;
                left1--;
                right1++;
            }
            //for even length palindromes
            int left2 = i;
            int right2 = i+1;
            while(left2>=0 && right2 < s.size() && s[left2] == s[right2]){
                count++;
                left2--;
                right2++;
            }
        }
        return count;
    }
};