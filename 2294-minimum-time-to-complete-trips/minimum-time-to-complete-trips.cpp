class Solution {
public:
    bool canComplete(vector<int>& time, int totalTrips, long long mid) {
        long long count = 0;

        for (int tim : time) {
            count += mid / tim;

            if (count >= totalTrips) return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long result = -1;
        long long left = 1;
        long long right = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canComplete(time, totalTrips, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};