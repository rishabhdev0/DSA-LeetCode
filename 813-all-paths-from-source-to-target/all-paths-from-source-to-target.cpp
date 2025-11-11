class Solution {
public:
    void dfs(int src, int target, vector<vector<int>>& result, vector<int>& temp, vector<vector<int>>& adj) {
        if (src == target) {
            result.push_back(temp);
            return;
        }
        
        for (auto neighbor : adj[src]) {
            temp.push_back(neighbor);
            dfs(neighbor, target, result, temp, adj);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            adj[i] = graph[i];
        }
        
        vector<vector<int>> result;
        vector<int> temp;
        temp.push_back(0); 
        dfs(0, n - 1, result, temp, adj);
        return result;
    }
};