class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
   
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        // Build adjacency list from adjacency matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    graph[i].push_back(j);
                }
            }
        }
        
        int count = 0;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++; // New province found
                dfs(graph, visited, i);
            }
        }
        
        return count;
    }
};