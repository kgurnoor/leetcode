class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack <long long> st;

        long long number = 0;
        long long result = 0;
        long long sign = 1;
        for(int i = 0; i < n;i++){
            if(isdigit(s[i])){
                number = number*10 + (s[i] - '0'); //number bnate chalo
            } else if (s[i] == '+'){
                //number jo bna pehle usko result mei add krdo
                result +=  sign*number;
                sign = 1;
                number = 0; //reset for the number after the sign
            } else if (s[i] == '-'){
                //number jo bna pehle usko result mei add krdo
                result += sign*number;
                sign = -1;
                number = 0; //reset for the number after the sign
            } else if (s[i] == '('){
                //bracket ke andar ka alag se result mei store hoga toh pehle vala result stack mei store krlo
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if (s[i] == ')'){
                //bracket khatam, result ko update krdo
                result += number*sign;
                number = 0;
                int last_sign = st.top(); 
                st.pop();
                int last_result = st.top();
                st.pop();
                result *= last_sign; 
                result += last_result;
            }
        }
        result += number*sign;
        return (int)result;
    }       
};