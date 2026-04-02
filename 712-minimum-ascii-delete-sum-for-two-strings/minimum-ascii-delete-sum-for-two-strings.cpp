class Solution {
public:
    int dp[1001][1001];

    int solve(string& s1, string& s2, int i, int j){
        if(i >= s1.length() || j >= s2.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // match
        if(s1[i] == s2[j]){
            return dp[i][j] = (int)s1[i] + solve(s1, s2, i+1, j+1);
        }

        // not match
        return dp[i][j] = max(
            solve(s1, s2, i+1, j),
            solve(s1, s2, i, j+1)
        );
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));

        int total = 0;
        for(char c : s1) total += c;
        for(char c : s2) total += c;

        int common = solve(s1, s2, 0, 0);

        return total - 2 * common;
    }
};