class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<int> left(n), right(n);
        stack<int> st;

        // previous smaller element index
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) left[i] = -1;
            else left[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next smaller element index
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) right[i] = n;
            else right[i] = st.top();

            st.push(i);
        }

        long long result = 0;

        for (int i = 0; i < n; i++) {
            int l = left[i] + 1;
            int r = right[i] - 1;

            long long sum = prefix[r + 1] - prefix[l];
            long long minProduct = sum * nums[i];

            result = max(result, minProduct);
        }

        return result % MOD;
    }
};