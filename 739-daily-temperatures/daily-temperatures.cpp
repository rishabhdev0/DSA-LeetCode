class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i;  // Calculate days difference
            }
            st.push(i);
        }
        return result;
    }
};