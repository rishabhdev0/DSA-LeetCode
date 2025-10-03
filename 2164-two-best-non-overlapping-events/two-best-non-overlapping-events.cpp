class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // Sort events by start time
        sort(events.begin(), events.end());
        
        // Min-heap: (end_time, value)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int maxSum = 0;
        int maxSoFar = 0;  // Track maximum value of events that ended before current event
        
        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];
            
            // Remove all events from heap that ended before current event starts
            while (!pq.empty() && pq.top().first < start) {
                maxSoFar = max(maxSoFar, pq.top().second);
                pq.pop();
            }
            
            // Current maximum is either:
            // 1. Take just this event: value
            // 2. Take this event + best previous non-overlapping event: value + maxSoFar
            maxSum = max(maxSum, value);
            maxSum = max(maxSum, value + maxSoFar);
            
            pq.push({end, value});
        }
        
        return maxSum;
    }
};