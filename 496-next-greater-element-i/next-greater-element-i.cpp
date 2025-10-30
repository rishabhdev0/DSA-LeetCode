class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>result;
        unordered_map<int , int>nextGreater;
        for(int num : nums2){
            while(!st.empty() && num > st.top()){
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for(int num : nums1){
            result.push_back(nextGreater.count(num) ? nextGreater[num] :  -1);
        }
        return result;
    }
};