class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int up = dp[i - 1][j];

                int leftDiag = INT_MAX;
                if (j > 0)
                    leftDiag = dp[i - 1][j - 1];

                int rightDiag = INT_MAX;
                if (j < n - 1)
                    rightDiag = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};