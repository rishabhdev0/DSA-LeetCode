class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                int sum = st.top() + asteroids[i];
                if(sum < 0){
                    st.pop();
                }else if(sum > 0){
                    asteroids[i] = 0;
                }else{
                    st.pop();
                    asteroids[i] = 0;
                }
            }
            if(asteroids[i] != 0){
                st.push(asteroids[i]);
            }
        }
        int si = st.size();
        vector<int>result(si);
        int last = si - 1;
        while(!st.empty()){
            result[last] = st.top();
            st.pop();
            last--;
        }
        return result;
    }
};