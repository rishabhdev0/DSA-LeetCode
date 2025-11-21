class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
       // map -> {stop , index(all that have routes)}
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }
        
        vector<bool> visitedRoute(routes.size(), false);
        queue<int> q;
        
       // all sources 
        for (int route : stopToRoutes[source]) {
            visitedRoute[route] = true;
            q.push(route);
        }
        
        int busCount = 1; // source bus
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                int route = q.front();
                q.pop();
                
                for (int stop : routes[route]) {
                    if (stop == target) return busCount;
                    
                   // unvisited , psuh them in queue
                    for (int nextRoute : stopToRoutes[stop]) {
                        if (!visitedRoute[nextRoute]) {
                            visitedRoute[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        
        return -1;
    }
};