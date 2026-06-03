class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;

            if (hours > h) return false;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int result = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isPossible(piles, h, mid)) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};