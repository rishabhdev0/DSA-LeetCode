class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {

        visited[node] = true;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);

        for(auto &edge : connections) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components = 0;

        vector<bool> visited(n,false);

        for(int i=0;i<n;i++) {

            if(!visited[i]) {

                dfs(i,adj,visited);
                components++;
            }
        }

        return components-1;
    }
};