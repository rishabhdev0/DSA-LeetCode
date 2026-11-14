class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st; // store idx only;
        int maxArea = 0;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int idx = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea , heights[idx] * width);
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea , heights[idx] * width);
        }
        return maxArea;
    }
};