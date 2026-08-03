class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> hashmap; //nums2 element -> nge 
        stack<int> st;
        vector<int> ans;
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            hashmap[nums2[i]] = st.empty()? -1 : st.top();
            st.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(hashmap[nums1[i]]);
        }
        return ans;
    }
};