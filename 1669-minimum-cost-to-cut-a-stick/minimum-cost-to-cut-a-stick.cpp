class Solution {
public:
    int dp[102][102];

    int solve(vector<int>& cuts, int left, int right) {
        if (left + 1 == right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int result = INT_MAX;

        for (int i = left + 1; i < right; i++) {
            int cost = (cuts[right] - cuts[left])
                     + solve(cuts, left, i)
                     + solve(cuts, i, right);

            result = min(result, cost);
        }

        return dp[left][right] = result;
    }

    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));

        cuts.push_back(n);
        cuts.push_back(0);

        sort(cuts.begin(), cuts.end());

        return solve(cuts, 0, cuts.size() - 1);
    }
};