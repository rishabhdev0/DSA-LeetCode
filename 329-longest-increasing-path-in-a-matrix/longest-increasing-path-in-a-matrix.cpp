class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    int dfs(vector<vector<int>>& matrix,
            vector<vector<int>>& dp,
            int i,
            int j) {

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int maxLength = 1;

        for (auto dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < n &&
                new_j >= 0 && new_j < m &&
                matrix[new_i][new_j] > matrix[i][j]) {

                int length = 1 + dfs(matrix, dp, new_i, new_j);

                maxLength = max(maxLength, length);
            }
        }

        return dp[i][j] = maxLength;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int max_len = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = dfs(matrix, dp, i, j);
                max_len = max(max_len, len);
            }
        }

        return max_len;
    }
};