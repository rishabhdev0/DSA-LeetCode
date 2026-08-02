class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, vector<int>& piles) {
        if (i > j)
            return 0;

        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeFirst =
            piles[i] +
            min(solve(i + 2, j, piles),
                solve(i + 1, j - 1, piles));

        int takeLast =
            piles[j] +
            min(solve(i, j - 2, piles),
                solve(i + 1, j - 1, piles));

        return dp[i][j] = max(takeFirst, takeLast);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));

        int total = accumulate(piles.begin(), piles.end(), 0);
        int alice = solve(0, piles.size() - 1, piles);
        int bob = total - alice;

        return alice > bob;
    }
};