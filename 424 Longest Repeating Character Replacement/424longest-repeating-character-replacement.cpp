class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> count;
        int maxfreq = 0;
        for (int right = 0; right < s.length(); right++) {
           
            char c = s[right];
            count[c] = count[c] + 1;
            if (count[c] >= maxfreq){
                maxfreq = count[c];
            }
            //for invalid window
            while (((right - left + 1) - maxfreq) > k ) {
                char leftChar = s[left];
                count[leftChar] = count[leftChar] - 1;
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};