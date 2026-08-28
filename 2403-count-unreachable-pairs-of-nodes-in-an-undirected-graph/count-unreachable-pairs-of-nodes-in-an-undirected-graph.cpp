class Solution {
public:
    int dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
        visited[node] = true;

        int count = 1;

        for (auto& neighbor : adj[node]) {
            if (!visited[neighbor]) {
                count += dfs(adj, neighbor, visited);
            }
        }

        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        long long ans = 0;
        long long remaining = n;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int cnt = dfs(adj, i, visited);

                ans += (long long)cnt * (remaining - cnt);

                remaining -= cnt;
            }
        }

        return ans;
    }
};