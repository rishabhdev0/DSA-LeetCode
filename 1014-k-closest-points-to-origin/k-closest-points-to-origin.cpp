class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: stores {distance, index}
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            
            pq.push({dist, i});
            
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Build the result
        vector<vector<int>> result;
        while(!pq.empty()) {
            int idx = pq.top().second;
            result.push_back(points[idx]);
            pq.pop();
        }
        
        return result;
    }
};