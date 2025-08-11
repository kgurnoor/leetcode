class Solution {
public:
    void f(int low, int high, vector<char>& s ) {
        while (low < high) {
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            low++;
            high--;
        }
    }
    void reverseString(vector<char>& s) {
        f(0,s.size()-1,s);
    }
};