class Solution {
public:
    int count = 0;
    
    void dfs(int start, int parent, vector<vector<pair<int, int>>>& adj) {
        for(auto &p : adj[start]) {
            int v = p.first;
            int check = p.second;
            if(v != parent) {
                if(check == 1) {
                    count++;
                }
                dfs(v, start, adj); 
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto con : connections) {
            int u = con[0];
            int v = con[1];
            adj[u].push_back({v, 1}); // real edge
            adj[v].push_back({u, 0}); // fake edge
        }
        dfs(0, -1, adj);
        return count;
    }
};