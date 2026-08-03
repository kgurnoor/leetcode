class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prevSmaller(n);
        vector<int> nextSmaller(n);
        stack<int> st;

        // Previous Smaller Element (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Next Smaller Element (smaller or equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;

            sum = (sum + (left * right % MOD) * arr[i]) % MOD;
        }

        return sum;
    }
};