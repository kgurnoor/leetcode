class Solution {
public:
    vector<int> nextGreater(vector<int>& nums2){
        int n = nums2.size();
        vector<int> nge(n,0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = -1;
            }else{
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }
        return nge;    
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ngefornums2 = nextGreater(nums2);
        vector <int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0;j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans[i] = ngefornums2[j];
                    break; //Once you've found the element in nums2, there's no need to continue searching.
                }
            }
        }
        return ans;
    }
};