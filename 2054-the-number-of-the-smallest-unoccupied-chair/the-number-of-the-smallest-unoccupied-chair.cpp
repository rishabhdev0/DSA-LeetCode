class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int targetArrival = times[targetFriend][0];
        
        // Sort by arrival time
        sort(times.begin(), times.end());
        
        // Min heap for available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        
        // Min heap for {departure_time, chair_number}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;
        
        int nextChair = 0;
        
        for (int i = 0; i < n; i++) {
            int arrivalTime = times[i][0];
            int departureTime = times[i][1];
            
            // Free up chairs where friends have departed
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrivalTime) {
                int freedChair = occupiedChairs.top().second;
                occupiedChairs.pop();
                availableChairs.push(freedChair);
            }
            
            // Assign the smallest available chair
            int assignedChair;
            if (!availableChairs.empty()) {
                assignedChair = availableChairs.top();
                availableChairs.pop();
            } else {
                assignedChair = nextChair++;
            }
            
            // find the friendarrivaltime chair 
            if (arrivalTime == targetArrival) {
                return assignedChair;
            }
            // Mark this chair as occupied
            occupiedChairs.push({departureTime, assignedChair});
        }
        
        return -1; 
    }
};