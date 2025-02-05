class Solution {
private:
    bool is_possible(vector<int>& ranks, int cars, long long min) {
        long long car_done = 0;
        for (auto r : ranks) {
            car_done += floor(sqrt(min / r));  
        }
        return car_done >= cars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1e14;
        long long result = high; 
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (is_possible(ranks, cars, mid)) {
                result = mid;  
                high = mid - 1;  
            } else {
                low = mid + 1;  
            }
        }

        return result;  // Return the minimum time found
    }
};
