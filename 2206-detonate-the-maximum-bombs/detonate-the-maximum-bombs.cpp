class Solution {
private:
    vector<vector<int>> adj;
    
    void dfs(vector<bool>& visited, int node, int& count) {
        visited[node] = true;
        count++;
        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(visited, neighbor, count);
            }
        }
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        adj.resize(n);
        
        // Build the graph
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                
                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long r1 = bombs[i][2];
                
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long r2 = bombs[j][2];
                
                long long dx = x2 - x1;
                long long dy = y2 - y1;
                long long distSq = dx * dx + dy * dy;
                
                // If bomb i can detonate bomb j
                if(distSq <= (long long)r1 * r1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int maxDetonate = 0;
        
        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = 0;
            dfs(visited, i, count);
            maxDetonate = max(maxDetonate, count);
        }
        
        return maxDetonate;
    }
};