class Solution {
public:
    int dp[101][101];
    int n;

    int solve(vector<vector<int>>& costs , int taken_a , int idx){
        if(idx == n){
            return 0;
        }

        if(dp[taken_a][idx] != -1){
            return dp[taken_a][idx];
        }

        int taken_b = idx - taken_a;
        int ans = INT_MAX;

        if(taken_a < n / 2){
            // sending to city A;
            ans = min(ans , costs[idx][0] + solve(costs , taken_a + 1, idx + 1));
        }

        // sending to city B;
        if(taken_b < n/2){
            ans = min(ans , costs[idx][1] + solve(costs , taken_a , idx+1));
        }

        return dp[taken_a][idx] = ans;

    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size();
        memset(dp , -1 , sizeof(dp));
        return solve(costs , 0 , 0);
    }
};