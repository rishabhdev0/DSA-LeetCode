class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int, int>>> adj(n);

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        int answer = -1;
        int minimum = INT_MAX;

        for(int i = 0; i < n; i++) {

            vector<int> dist(n, INT_MAX);

            priority_queue<
                pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>
            > pq;

            dist[i] = 0;

            // {distance, node}
            pq.push({0, i});

            while(!pq.empty()) {

                auto [distance, node] = pq.top();
                pq.pop();

                if(distance > dist[node])
                    continue;

                for(auto [neighbor, cost] : adj[node]) {

                    int newDist = distance + cost;

                    if(newDist < dist[neighbor]) {

                        dist[neighbor] = newDist;

                        pq.push({newDist, neighbor});
                    }
                }
            }

            // Count reachable cities
            int count = 0;

            for(int j = 0; j < n; j++) {

                if(j != i && dist[j] <= distanceThreshold) {
                    count++;
                }
            }

            // Tie -> choose larger city number
            if(count <= minimum) {
                minimum = count;
                answer = i;
            }
        }

        return answer;
    }
};