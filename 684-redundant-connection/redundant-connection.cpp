class Solution {
public:
    bool dfs(int start , int end , vector<bool> &visited , vector<vector<int>> &adj){
        if(start == end){
            return true;
        }
        visited[start] = true;
        for(int neighbor : adj[start]){
            if(!visited[neighbor]){
                if(dfs(neighbor , end , visited , adj)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            vector<bool>visited(n + 1 , false);
            if(dfs(u , v , visited , adj)){
                return {u , v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};