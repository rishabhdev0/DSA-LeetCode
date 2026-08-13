class Solution {
public:
    int n;
    int dp[101][101];

    bool solve(string& s, int open, int idx) {

        if(open < 0)
            return false;

        if(open > n - idx)
            return false;

        if(idx == n)
            return open == 0;

        if(dp[open][idx] != -1)
            return dp[open][idx];

        bool check = false;

        if(s[idx] == '(') {
            check = solve(s, open + 1, idx + 1);
        }
        else if(s[idx] == ')') {
            check = solve(s, open - 1, idx + 1);
        }
        else {
            // '*' -> '('
            check |= solve(s, open + 1, idx + 1);

            // '*' -> ')'
            check |= solve(s, open - 1, idx + 1);

            // '*' -> empty
            check |= solve(s, open, idx + 1);
        }

        return dp[open][idx] = check;
    }

    bool checkValidString(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 0);
    }
};