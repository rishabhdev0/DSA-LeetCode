class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Classic Dijkstra
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        pq.push({0, 0, 1});

        vector<vector<int>> result(n, vector<int>(k + 1, INT_MAX));

        result[0][1] = 0;

        while(!pq.empty()){
            auto [wt, node, count] = pq.top();
            pq.pop();

            if(wt > result[node][count]) continue;

            if(node == n - 1) return wt;

            for(auto neighbor : adj[node]){
                int new_node = neighbor.first;
                int new_wt = neighbor.second;

                int new_Count = (labels[node] == labels[new_node] 
                                 ? count + 1 : 1);

                if(new_Count > k) continue;

                if(wt + new_wt < result[new_node][new_Count]){
                    result[new_node][new_Count] = wt + new_wt;

                    pq.push({wt + new_wt, new_node, new_Count});
                }
            }
        }

        return -1;
    }
};