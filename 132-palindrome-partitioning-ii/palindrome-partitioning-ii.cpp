class Solution {
public:
    int dp[2001][2001];

    bool isPali(string &s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    int solve(int i, int j, string &s) {

        if (i >= j)
            return 0;

        if (isPali(s, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int result = INT_MAX;

        for (int k = i; k < j; k++) {

            if (isPali(s, i, k)) {

                int temp = 1 + solve(k + 1, j, s);

                result = min(result, temp);
            }
        }

        return dp[i][j] = result;
    }

    int minCut(string s) {

        memset(dp, -1, sizeof(dp));

        return solve(0, s.length() - 1, s);
    }
};