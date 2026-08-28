class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int, int>>>& adj,
             vector<bool>& visited) {
        
        visited[node] = true;

        for (auto& [neighbor, cost] : adj[node]) {
            ans = min(ans, cost);
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int cost = road[2];

            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        vector<bool> visited(n + 1, false);

        dfs(1, adj, visited);

        return ans;
    }
};