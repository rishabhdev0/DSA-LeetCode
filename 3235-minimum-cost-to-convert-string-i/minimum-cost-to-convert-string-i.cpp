class Solution {
public:
    void dijkstra(int src,
     vector<vector<pair<int,int>>> &adj,  vector<vector<long long>> &dist) {

        priority_queue<pair<long long,int>, vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;


        dist[src][src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[src][u]) continue;

            for(auto &edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if(dist[src][v] > d + w) {
                    dist[src][v] = d + w;
                    pq.push({dist[src][v], v});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original,vector<char>&  changed,vector<int>& cost) {
                          
        vector<vector<pair<int,int>>> adj(26);

        for(int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }

        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));

    
        for(int i = 0; i < 26; i++) {
            dijkstra(i, adj, dist);
        }

        long long ans = 0;

        for(int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(dist[u][v] == LLONG_MAX) return -1;
            ans += dist[u][v];
        }

        return ans;
    }
};
