class Solution {
private:
    bool canShip(vector<int>& weights, int capacity, int days) {
        int currentLoad = 0;
        int requiredDays = 1; 
        
        for(int weight : weights) {
            // If adding this weight exceeds capacity, we need a new day
            if(currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = 0;
                
                // If we've exceeded the allowed days, return false
                if(requiredDays > days) {
                    return false;
                }
            }
            currentLoad += weight;
        }
        
        return requiredDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        int result = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(canShip(weights, mid, days)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1; // Need larger capacity
            }
        }
        
        return result;
    }
};