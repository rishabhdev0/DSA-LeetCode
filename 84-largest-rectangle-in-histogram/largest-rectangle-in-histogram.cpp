class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st; // {startIndex, height}
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                int index = st.top().first;
                int height = st.top().second;
                st.pop();

                max_area = max(max_area, height * (i - index));
                start = index;
            }

            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();

            max_area = max(max_area, height * (n - index));
        }

        return max_area;
    }
};