class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int , int>>st; //  {lowest_index till now , heights};
        int maxArea = 0;
        for(int  i = 0 ; i < n ; i++){
            int currIdx = i;
            while(!st.empty() && st.top().second > heights[i]){
                int height = st.top().second;
                int small_idx = st.top().first;

                st.pop();


                maxArea = max(maxArea , height * (i - small_idx));
                currIdx = small_idx;
            }
            st.push({currIdx , heights[i]});
        }
        while(!st.empty()){
            int index = st.top().first;
            int height = st.top().second;
            st.pop();
            maxArea = max(maxArea , height * (n - index));
        }
        return maxArea;
    }
};