class Solution {
public:
    void dfs(
        int node,
        vector<vector<int>>& adj,int& vertexCount , int& degreeSum , vector<bool>& visited){
        visited[node] = true;

        vertexCount++;
        degreeSum += adj[node].size();

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adj, vertexCount, degreeSum, visited);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertexCount = 0;
                int degreeSum = 0;

                dfs(i, adj, vertexCount, degreeSum, visited);

                if (degreeSum == vertexCount * (vertexCount - 1)) {
                    result++;
                }
            }
        }

        return result;
    }
};