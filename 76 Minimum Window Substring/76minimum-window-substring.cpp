class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "" ;
        }
        unordered_map<char , int > count_t, count_s;
        for (char c : t){
            count_t[c]++;
        }
        int have = 0;
        int need = count_t.size();
        int left = 0; 
        int start_index = 0;
        int minLen = INT_MAX;
        // unordered_map<char , int > count_s; instead of doing this, write along line 7 only
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            count_s[c] ++; 
            // Only increase `have` if current char count matches t's requirement
            if (count_t.find(c) != count_t.end() && count_s[c] == count_t[c]) {
                have++;
            }

            while(have == need){
                // Update result
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start_index = left;
                }
                // Pop from the left
                char leftChar = s[left];
                count_s[leftChar]--;
                if (count_t.find(leftChar) != count_t.end() && count_s[leftChar] < count_t[leftChar]) {
                    have--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start_index, minLen);

    }
};