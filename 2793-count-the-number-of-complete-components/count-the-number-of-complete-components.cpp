class Solution {
public:
    void dfs(vector<vector<int>>& adj , int node , int& edgeCount , vector<bool>& visited , int& nodeCount){
        visited[node] = true;
        edgeCount++;

        nodeCount += adj[node].size();

        for(auto neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(adj , neighbor , edgeCount , visited , nodeCount);
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        vector<bool>visited(n , false);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                int edgeCount = 0;
                int nodeCount = 0;
                dfs(adj , i , edgeCount , visited , nodeCount);
                if(nodeCount == edgeCount * (edgeCount - 1)){
                    count++;
                }
            }
        }
        return count;
    }
};