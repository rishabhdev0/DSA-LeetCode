class Solution {
private:
    int find_max(const vector<int>& weights) {
        int maxi = INT_MIN;
        for (int weight : weights) {
            maxi = max(weight, maxi);
        }
        return maxi;
    }

    int find_sum(const vector<int>& weights) {
        int totalweight = 0;
        for (int weight : weights) {
            totalweight += weight;
        }
        return totalweight;
    }

    bool canShip(const vector<int>& weights, int capacity, int days) {
        int load = 0;
        int dayCount = 1;
        for (int weight : weights) {
            if (load + weight > capacity) {
                dayCount++;
                load = weight;
                if (dayCount > days) {
                    return false;
                }
            } else {
                load += weight;
            }
        }
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = find_max(weights);
        int right = find_sum(weights);
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, mid, days)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};