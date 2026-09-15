class Solution {
public:
    int dp[2001][2001];
    vector<vector<bool>> isPali;

    int solve(string &s, int k, int i, int j) {

        // invalid range
        if (i >= s.size() || j >= s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int grow = 0;
        int move = 0;
        int take = 0;

        // Don't take current [i...j]
        // Grow the current substring
        grow = solve(s, k, i, j + 1);

        // Move starting point
        move = solve(s, k, i + 1, j);

        // If [i...j] is a palindrome AND length >= k
        if (j - i + 1 >= k && isPali[i][j]) {

            // Take [i...j]
            // Next substring must start after j
            take = 1 + solve(s, k, j + 1, j + 1 + k - 1);
        }

        return dp[i][j] = max({take, grow, move});
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();

        memset(dp, -1, sizeof(dp));

        isPali.assign(n, vector<bool>(n, false));

        // Palindrome preprocessing
        for (int L = 1; L <= n; L++) {

            for (int i = 0; i + L <= n; i++) {

                int j = i + L - 1;

                if (L == 1) {
                    isPali[i][j] = true;
                }
                else if (L == 2) {
                    isPali[i][j] = (s[i] == s[j]);
                }
                else {
                    isPali[i][j] =
                        (s[i] == s[j] &&
                         isPali[i + 1][j - 1]);
                }
            }
        }

        return solve(s, k, 0, k - 1);
    }
};