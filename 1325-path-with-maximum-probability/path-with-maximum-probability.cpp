class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int, double>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> dist(n, 0.0);

        priority_queue<
            pair<double, int>
        > pq;

        pq.push({1.0, start_node});
        dist[start_node] = 1.0;

        while(!pq.empty()) {

            auto [prob, node] = pq.top();
            pq.pop();

            if(node == end_node) {
                return prob;
            }

            for(auto& [neighbor, edgeProb] : adj[node]) {

                double newProb = prob * edgeProb;

                if(newProb > dist[neighbor]) {

                    dist[neighbor] = newProb;

                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0;
    }
};