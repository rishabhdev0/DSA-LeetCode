class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>>adj(n);

        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int c = flight[2];
            adj[u].push_back({v , c});
        }
        vector<int>dist(n , INT_MAX);
        queue<pair<int , int>>que;
        que.push({src , 0});
        dist[src] = 0;

        while(!que.empty() && k >= 0){
            int sz = que.size();
            for(int i = 0 ; i < sz ; i++){
                auto[node , cost] = que.front();
                que.pop();
                for(auto &[next , price] : adj[node]){
                    if(cost + price < dist[next]){
                       dist[next] = cost + price;
                       que.push({next , dist[next]});
                    }
                }
            }
            k--;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};