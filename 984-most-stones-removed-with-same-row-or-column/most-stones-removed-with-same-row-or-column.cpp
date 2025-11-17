class Solution {
private:
    void dfs(vector<vector<int>>& stones, vector<bool>& visited, int index) {
        visited[index] = true;
        int n = stones.size();
        int currentRow = stones[index][0];
        int currentCol = stones[index][1];
        
        for(int i = 0; i < n; i++) {
            if(!visited[i] && (stones[i][0] == currentRow || stones[i][1] == currentCol)) {
                dfs(stones, visited, i);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int group = 0;
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(stones, visited, i);
                group++;
            }
        }
        
        return n - group;
    }
};