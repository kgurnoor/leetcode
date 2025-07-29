class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        //primitive pair of brackets = one open and one close, to be added in result
        int opened = 0; 
        for(char c: s){
            //opening bracket present 
            if(c == '(' && opened++ > 0) res+=c; 
            if(c == ')' && opened-- > 1) res+=c; 
        }
        return res;
    }
};