class Solution {
public:
    int dp[100001];
    int solve(int idx, int n, vector<int>& costs) {
        if (idx == n) return 0;

        if(dp[idx] != -1){
             return dp[idx];
        }

        int cost = INT_MAX;

        int j = idx + 1;
        if (j <= n) {
            cost = min(cost, costs[j - 1] + (j - idx) * (j - idx)
                              + solve(j, n, costs));
        }

        j = idx + 2;
        if (j <= n) {
            cost = min(cost, costs[j - 1] + (j - idx) * (j - idx)
                              + solve(j, n, costs));
        }

        j = idx + 3;
        if (j <= n) {
            cost = min(cost, costs[j - 1] + (j - idx) * (j - idx)
                              + solve(j, n, costs));
        }

        return dp[idx] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1 , sizeof(dp));
        return solve(0, n, costs);
    }
};