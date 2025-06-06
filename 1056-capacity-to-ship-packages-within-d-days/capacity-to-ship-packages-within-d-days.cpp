class Solution {
private:
    bool can_ship(vector<int>& weights, int days, int capacity) {
        int load = 0;
        int day_count = 1;

        for (int weight : weights) {
            if (load + weight > capacity) {
                day_count++;      
                load = weight;    
            } else {
                load += weight;
            }
        }

        return day_count <= days; 
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (can_ship(weights, days, mid)) {
                result = mid;
                right = mid - 1;  
            } else {
                left = mid + 1;  
            }
        }

        return result;
    }
};
