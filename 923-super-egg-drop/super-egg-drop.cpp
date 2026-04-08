vector<vector<int>> dp;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int k, int n){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;

        if(dp[k][n] != -1) return dp[k][n];

        int low = 1, high = n;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;

            int break_case = solve(k-1, mid-1);
            int not_break = solve(k, n-mid);

            int temp = 1 + max(break_case, not_break);

            if(break_case > not_break){
                high = mid - 1;
            } else {
                low = mid + 1;
            }

            ans = min(ans, temp);
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        dp.resize(k+1, vector<int>(n+1, -1)); 
        return solve(k, n);
    }
};