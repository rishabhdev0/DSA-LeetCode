class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>row_count(n);
        vector<int>col_count(m);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        int answer = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j  = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    if(row_count[i] > 1 || col_count[j] > 1){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};