class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq; // max-heap to track climbs
        
        for (int i = 0; i < n - 1; i++) { 
    
            if (heights[i] >= heights[i + 1]) {
                continue;
            }
            
            int climb = heights[i + 1] - heights[i];
            
            // Use bricks first
            bricks -= climb;
            pq.push(climb); // Remember this climb
            
            // If we used too many bricks
            if (bricks < 0) {
                if (ladders > 0) {
                    // Use ladder for the largest climb instead of bricks
                    bricks += pq.top(); // Get bricks back for the largest climb
                    pq.pop();
                    ladders--;
                } else {
                    return i;
                }
            }
        }
        return n - 1;
    }
};