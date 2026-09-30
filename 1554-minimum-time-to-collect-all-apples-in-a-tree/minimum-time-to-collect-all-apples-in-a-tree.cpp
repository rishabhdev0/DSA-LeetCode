class Solution {
public:
    int dfs(vector<vector<int>>& adj , int curr , int parent, vector<bool>& hasApple){

        int time = 0;
        for(auto& child : adj[curr]){
            if(child == parent) continue;
            int child_time = dfs(adj , child  , curr , hasApple);

            if(child_time > 0 || hasApple[child]){
                time += child_time + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj , 0 , -1 , hasApple);
    }
};