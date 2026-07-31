class Solution {
public:
    int minimumPushes(string word) {
        vector <int> freq(26, 0);
        int ans = 0;
        for(char c: word){
            freq[c - 'a']++; //counted frequencies of all letters
        }
        sort(freq.begin(),freq.end()); //we dont care about which letter we just want highest freq->cheapest cost
        for(int i = 25; i >= 0; i--){
            ans += ((25-i)/8 + 1)*freq[i];
        }
        return ans;
    }
};