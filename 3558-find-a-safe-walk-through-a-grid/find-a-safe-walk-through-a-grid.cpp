class Solution {
public:
    vector<vector<int>>directions = {{-1 , 0} , {1 , 0} , {0 , 1} , {0 , -1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         int n = grid.size();
         int m = grid[0].size();
         health -= grid[0][0];
         if(health <= 0) return false;
         queue<pair<int , pair<int , int>>>que; // {health , {index_i , index_j}};
         vector<vector<int>>best(n , vector<int>(m , -1));
         que.push({health , {0 , 0}});
         best[0][0] = health;

         while(!que.empty()){
             int currHealth = que.front().first;
             int curr_i = que.front().second.first;
             int curr_j = que.front().second.second;

             que.pop();

             if(curr_i == n - 1 && curr_j == m - 1){
                return true;
             }

             for(auto& dir : directions){
               int new_i = curr_i + dir[0];
               int new_j = curr_j + dir[1];

               if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m) continue;

               int newHealth = currHealth - grid[new_i][new_j];

               if (newHealth <= 0) continue;

               if(newHealth > best[new_i][new_j]){
                  best[new_i][new_j] = newHealth;
                  que.push({newHealth , {new_i , new_j}});
                 }
             }
         }
         return false;
    }
};