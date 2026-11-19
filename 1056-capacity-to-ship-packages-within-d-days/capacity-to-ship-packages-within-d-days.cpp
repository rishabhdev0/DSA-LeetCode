class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int sum = 0;
        int dayCount = 1;

        for(int weight : weights) {
            sum += weight;

            if(sum > capacity) {
                dayCount++;
                sum = weight;
            }
        }

        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        long long high = 0;

        for(auto weight : weights) {
            low = max(low, weight);
            high += weight;
        }

        int result = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canShip(weights, days, mid)) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return result;
    }
};
