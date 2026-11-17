class Solution {
public:
    vector<vector<int>>dp;

    int solve(int k , int n){
        if(k == 1 || n == 1 || n == 0) return n;
        if(dp[k][n] != -1)
           return dp[k][n];
        
        int low = 1;
        int high = n;
        int result = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int break_case = solve(k-1 , mid - 1);
            int not_break = solve(k , n - mid);
            int count = 1 + max(break_case , not_break);
            if(break_case > not_break){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            result = min(result , count);
        }
        return dp[k][n] = result;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1 , vector<int>(n+1 , -1));
        return solve(k , n);
    }
};