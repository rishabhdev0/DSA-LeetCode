class Solution {
public:
    int dp[101][101];

    bool solve(string& s, int n, int open, int idx){
        if(open < 0) return false;

        // 🔥 Important bounds
        if(open > n) return false;
        if(open > n - idx) return false;

        if(idx == n){
            return open == 0;
        }

        if(dp[idx][open] != -1){
            return dp[idx][open];
        }

        bool check = false;

        if(s[idx] == '('){
            check |= solve(s, n, open + 1, idx + 1);
        }
        else if(s[idx] == ')'){
            if(open > 0)
                check |= solve(s, n, open - 1, idx + 1);
        }
        else { // '#'
            check |= solve(s, n, open + 1, idx + 1); // '('

            if(open > 0)
                check |= solve(s, n, open - 1, idx + 1); // ')'

            check |= solve(s, n, open, idx + 1); // empty
        }

        return dp[idx][open] = check;
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, s.length(), 0, 0);
    }
};