class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        queue<pair<int, int>> q; // {node, cost}
        q.push({src, 0});
        int stops = 0;
        
        while(!q.empty() && stops <= k){
            int size = q.size();
            vector<int> temp = dist; // Temporary array to avoid using same iteration updates
            
            for(int i = 0; i < size; i++){
                auto [node, cost] = q.front();
                q.pop();
                
                for(auto &[neighbor, price] : adj[node]){
                    int newCost = cost + price;
                    if(newCost < temp[neighbor]){
                        temp[neighbor] = newCost;
                        q.push({neighbor, newCost});
                    }
                }
            }
            dist = temp; // Update 
            stops++;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};