class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int minCount = INT_MAX;
        int result = 0;
        
        // Run Dijkstra from each city
        for(int i = 0; i < n; i++){
            vector<int> dist(n, INT_MAX);
            dist[i] = 0; 
            
            // Min-heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            
            while(!pq.empty()){
                int currentDist = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                // Skip if we found a better path already
                if(currentDist > dist[node]) continue;
                
                for(auto& neighbor : adj[node]){
                    int nextNode = neighbor.first;
                    int weight = neighbor.second;
                    int newDist = currentDist + weight;
                    
                    if(newDist < dist[nextNode]){
                        dist[nextNode] = newDist;
                        pq.push({newDist, nextNode});
                    }
                }
            }
            
            // Count reachable cities within threshold
            int count = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[j] <= distanceThreshold){
                    count++;
                }
            }
            
            // Update result (choose city with smallest count, largest number in case of tie)
            if(count <= minCount){
                minCount = count;
                result = i;
            }
        }
        
        return result;
    }
};