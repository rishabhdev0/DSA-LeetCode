class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int curr_pass = 0;
        // Min-heap: {end_time, passengers}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (const auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            
            // Remove all completed trips before current pickup
            while (!pq.empty() && pq.top().first <= start) {
                curr_pass -= pq.top().second;
                pq.pop();
            }
            
            // Add current trip
            curr_pass += passengers;
            pq.push({end, passengers});
            
            if (curr_pass > capacity) {
                return false;
            }
        }
        
        return true;
    }
};