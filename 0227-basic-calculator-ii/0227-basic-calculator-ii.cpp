class Solution {
public:
    int calculate(string s) {
        s += '+';

        int result = 0;
        int lastNumber = 0;
        int number = 0;
        char op = '+';

        for (char c : s) {

            if (c == ' ')
                continue;

            if (isdigit(c)) {
                number = number * 10 + (c - '0');
                continue;
            }

            if (op == '+') {
                result += lastNumber;
                lastNumber = number;
            }
            else if (op == '-') {
                result += lastNumber;
                lastNumber = -number;
            }
            else if (op == '*') {
                lastNumber *= number;
            }
            else if (op == '/') {
                lastNumber /= number;
            }

            op = c;
            number = 0;
        }

        return result + lastNumber;
    }
};