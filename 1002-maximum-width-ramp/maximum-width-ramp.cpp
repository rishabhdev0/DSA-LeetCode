class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(st.empty() || nums[st.top()]>=nums[i]){
                st.push(i);
            }
        }
        int ramp_width = 0;
        int j = n-1;
        while(j>=0){
            while(!st.empty() && nums[st.top()]<=nums[j]){
                int i = st.top();
                ramp_width = max(ramp_width , j-i);
                st.pop();
            }
            j--;
        }
        return ramp_width;
    }
};