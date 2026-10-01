class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 0 = RED
        // 1 = BLUE
        vector<vector<pair<int , int>>>adj(n);
        for(auto edge : redEdges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v , 0});
        }

        for(auto edge : blueEdges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v , 1});
        }
        vector<int>answer(n , -1);
        vector<vector<bool>>visited(n , vector<bool>(2 , false));
        queue<pair<int , int>>que;
        // start with any color;
        que.push({0 , 0});
        que.push({0 , 1});

        visited[0][0] = true;
        visited[0][1] = true;

        int distance = 0;
        while(!que.empty()){
            int siz = que.size();
            while(siz--){
                auto[node , prevColor] = que.front();
                que.pop();
                answer[node] = answer[node] == -1 ? distance : min(answer[node] , distance);
                for(auto[neighbor , color] : adj[node]){
                    if(color == prevColor) continue;
                    if(visited[neighbor][color]) continue;
                    visited[neighbor][color] = true;
                    que.push({neighbor , color});
                }
            }
            distance++;
        }
        return  answer;
    }
};