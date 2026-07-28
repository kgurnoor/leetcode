class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++; 
        }
        string left = "";
        string mid = "";
        for(int i = 0; i < 26; i++){
            //string.append(number_of_times, character);
            left.append(freq[i]/2, 'a' + i);
            //string s = "";
            // s.append(4, 'x');
            // s = "xxxx"
            if(freq[i] % 2){ //if this exists, meaning a remainder exists
                mid = 'a' + i; //ascii value of ith letter
            }
        }
        string right = left;
        reverse(right.begin(),right.end());
        return left+mid+right;
    }
};