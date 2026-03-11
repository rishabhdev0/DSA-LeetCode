class Solution {
public:
    int dp[301][301];
    int solve(vector<vector<char>>& matrix , int i , int j){
        int n = matrix.size();
        int m = matrix[0].size();
        if(i >= n || j >=m) return 0;
        if(matrix[i][j] == '0') return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(matrix , i +1 , j);
        int diagonal = solve(matrix , i+1 , j + 1);
        int left = solve(matrix , i , j+1);

        return dp[i][j] = 1 + min({right , diagonal , left});

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp , -1 , sizeof(dp));
        int max_len = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1'){
                    max_len = max(max_len , solve(matrix , i , j));
                }
            }
        }
        return max_len * max_len;
    }
};