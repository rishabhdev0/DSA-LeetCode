class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = values[0]; 
        int ans = INT_MIN;

        for (int j = 1; j < values.size(); j++) {
            ans = max(ans, best + values[j] - j);
            best = max(best, values[j] + j);
        }

        return ans;
    }
};
