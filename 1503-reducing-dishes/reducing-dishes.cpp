// class Solution {
// public:
//     int dp[501][501];

//     int solve(vector<int>& satisfaction, int idx, int time) {
//         if (idx >= satisfaction.size()) return 0;

//         if (dp[idx][time] != -1) {
//             return dp[idx][time];
//         }

//         int include = satisfaction[idx] * time +
//                       solve(satisfaction, idx + 1, time + 1);

//         int not_include = solve(satisfaction, idx + 1, time);

//         return dp[idx][time] = max(include, not_include);
//     }

//     int maxSatisfaction(vector<int>& satisfaction) {
//         memset(dp, -1, sizeof(dp));

//         sort(satisfaction.begin(), satisfaction.end()); 

//         return solve(satisfaction, 0, 1);
//     }
// };


// tabulation 

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int time = 1; time <= n; time++) {

                int include = satisfaction[i] * time + dp[i + 1][time + 1];
                int exclude = dp[i + 1][time];

                dp[i][time] = max(include, exclude);
            }
        }

        return dp[0][1];
    }
};
