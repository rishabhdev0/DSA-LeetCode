
class Solution {
public:
    typedef long long ll;

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Prefix Sum
        vector<ll> cumSum(n);
        cumSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            cumSum[i] = nums[i] + cumSum[i - 1];
        }

        auto rangeSum = [&](int i, int j) -> ll {
            if (i > j) return 0LL;

            return cumSum[j] - ((i > 0) ? cumSum[i - 1] : 0LL);
        };

        // Next Greater Right
        vector<int> NGR(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                NGR[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // Precompute operation costs
        vector<ll> operation(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int m = NGR[i];

            ll segops = (1LL * nums[i] * (m - i))
                        - rangeSum(i, m - 1);

            operation[i] = operation[m] + segops;
        }

        // Sliding Window + Monotonic Deque
        deque<int> dq;

        ll result = 0;
        int i = 0;
        int j = 0;

        while (j < n) {

            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            while (i <= j) {
                int m = dq.front();

                ll opsCount = (operation[i] - operation[m])
                            + (1LL * nums[m] * (j - m + 1))
                            - rangeSum(m, j);

                if (opsCount <= k) break;

                i++;

                if (dq.front() < i) {
                    dq.pop_front();
                }
            }

            result += (j - i + 1);

            j++;
        }

        return result;
    }
};
