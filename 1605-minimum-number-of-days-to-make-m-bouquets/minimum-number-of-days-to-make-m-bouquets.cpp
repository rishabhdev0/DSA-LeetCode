class Solution {
public:
    bool canBloom(vector<int>& bloomDay, int days, int m, int k) {
        int n = bloomDay.size();
        int count = 0;
        int check = 0;

        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= days) {
                count++;
            }
            else {
                count = 0;
            }
            if(count >= k) {
                count = 0;
                check++;
            }
        }

        return check >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(1LL * m * k > n) return -1;

        int result = -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canBloom(bloomDay, mid, m, k)) {
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
