class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        visited[node] = true;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(adj, visited, neighbor);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);

        for (auto connect : connections) {
            int u = connect[0];
            int v = connect[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int groups = 0;

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                groups++;
            }
        }

        return groups - 1;
    }
};