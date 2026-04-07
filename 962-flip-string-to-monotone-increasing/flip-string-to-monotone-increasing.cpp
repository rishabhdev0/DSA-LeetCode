class Solution {
public:
    int dp[100001][2];

    int solve(string &s, bool rev, int idx) {
        if (idx >= s.length()) return 0;

        if (dp[idx][rev] != -1) return dp[idx][rev];

        int flip = INT_MAX;

        if (s[idx] == '0') {
            if (!rev) {
                // stay 0
                int not_flip = solve(s, rev, idx + 1);

                // flip to 1 and move to rev = 1
                int do_flip = 1 + solve(s, 1, idx + 1);

                flip = min(not_flip, do_flip);
            } else {
                flip = 1 + solve(s, rev, idx + 1);
            }
        } 
        else { // s[idx] == '1'
            if (!rev) {
                // Option 1: keep 1 and switch to rev = 1
                int not_flip = solve(s, 1, idx + 1);

                // Option 2: flip 1 → 0 and stay in rev = 0
                int do_flip = 1 + solve(s, 0, idx + 1);

                flip = min(not_flip, do_flip);
            } else {
                flip = solve(s, rev, idx + 1);
            }
        }

        return dp[idx][rev] = flip;
    }

    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0);
    }
};