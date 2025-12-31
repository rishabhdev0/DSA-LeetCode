class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int currentPassengers = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (auto& trip : trips) {
            int numPassengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            
           
            while (!pq.empty() && pq.top().first <= start) {
                currentPassengers -= pq.top().second;
                pq.pop();
            }
            
            currentPassengers += numPassengers;
            
            if (currentPassengers > capacity) {
                return false;
            }
            
            pq.push({end, numPassengers});
        }
        
        return true;
    }
};