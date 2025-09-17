class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size()-1;
        while (low < high){
            //If you keep skipping non-alphanumeric characters without checking low < high, you might end up accessing invalid indices.
            // Move low forward if not alphanumeric
            while(low<high && !isalnum(s[low])) { 
                low++;
            }
            // Move high backward if not alphanumeric
            while(low<high && !isalnum(s[high])){
                high--;
            }
            if(tolower(s[low]) != tolower(s[high])){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};
