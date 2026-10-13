class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 3;

        vector<long long> left_dp(3 * n);
        vector<long long> right_dp(3 * n);

        long long sum = 0;
        priority_queue<int> max_heap;

        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i];
            max_heap.push(nums[i]);

            if (max_heap.size() > n) {
                sum -= max_heap.top();
                max_heap.pop();
            }

            if (i >= n - 1) {
                left_dp[i] = sum;
            }
        }

        sum = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 3 * n - 1; i >= n; i--) {
            sum += nums[i];
            min_heap.push(nums[i]);

            if (min_heap.size() > n) {
                sum -= min_heap.top();
                min_heap.pop();
            }

            if (i <= 2 * n) {
                right_dp[i] = sum;
            }
        }

        long long mindiff = LLONG_MAX;

        for (int i = n - 1; i < 2 * n; i++) {
            long long diff = left_dp[i] - right_dp[i + 1];
            mindiff = min(diff, mindiff);
        }

        return mindiff;
    }
};