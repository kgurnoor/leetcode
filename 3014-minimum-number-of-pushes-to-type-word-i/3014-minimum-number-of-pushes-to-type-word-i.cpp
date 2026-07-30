class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int q = n/8;
        int r = n%8;
        int result = 0;
        if(q==0) return n;
        else if(q == 1){
            result = (8*(1) + (r*(q+1)));
        }else if(q == 2){
            result = (8*(1+2) + (r*(q+1)));
        }else if(q==3){
            result = (8*(1+2+3) + (r*(q+1)));
        }
        return result;
    }
};