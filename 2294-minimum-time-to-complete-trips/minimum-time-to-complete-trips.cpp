class Solution {
private:
    bool ispossible(vector<int>& time, int totalTrips, long long giventime) {
        long long actualtrips = 0;
        for (int t : time) {
            actualtrips += giventime / t;
        }
        return actualtrips >= totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = (long long) *max_element(time.begin(), time.end()) * totalTrips; 
        long long result = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (ispossible(time, totalTrips, mid)) {
                result = mid;
                right = mid - 1;  
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
