class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        queue<pair<int,int>> pq;

        // push all 0s
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    pq.push({i, j});
                } else {
                    mat[i][j] = -1; // mark unvisited
                }
            }
        }

        // BFS
        while(!pq.empty()){
            auto [x, y] = pq.front();
            pq.pop();

            for(auto [dx, dy] : dir){
                int new_x = x + dx;
                int new_y = y + dy;

                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m 
                   && mat[new_x][new_y] == -1){

                    mat[new_x][new_y] = mat[x][y] + 1;
                    pq.push({new_x, new_y});
                }
            }
        }

        return mat;
    }
};