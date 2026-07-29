class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        char op = '+';
        int number = 0;
        stack<int> st;
        s += '+'; //Appending '+' ensures the last number gets processed.
        for(int i = 0; i < n+1; i++){
            if(s[i] == ' '){
                continue; //empty space
            } 
            if(isdigit(s[i])){ //if digit is encountered in string
                number = number*10 + (s[i] - '0');
                continue;
            }if (op == '+'){ //delay the result
                st.push(number); 
            }else if(op == '-'){
                st.push(-1*number);
            }else if(op == '*'){
                int top = st.top();
                st.pop();
                st.push(top*number); //calculate result immediately
            }else if(op == '/'){
                int top = st.top();
                st.pop();
                st.push(top/number);
            }
            op = s[i]; //saving last operator
            number = 0;
        }
        int result= 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};