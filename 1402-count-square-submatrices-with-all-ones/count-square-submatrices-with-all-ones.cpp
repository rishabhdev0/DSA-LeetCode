class Solution {
public:
    int dp[301][301];

    int solve(vector<vector<int>>& matrix , int i , int j){
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(matrix[i][j] == 0) return dp[i][j] = 0;

        int right = solve(matrix , i , j + 1);
        int diagonal = solve(matrix , i + 1 , j + 1);
        int down = solve(matrix , i + 1 , j);

        return dp[i][j] = 1 + min(right , min(diagonal , down));
    }

    int countSquares(vector<vector<int>>& matrix) {
        memset(dp , -1 , sizeof(dp));

        int n = matrix.size();
        int m = matrix[0].size();
        int answer = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 1){
                    answer += solve(matrix , i , j);
                }
            }
        }

        return answer;
    }
};