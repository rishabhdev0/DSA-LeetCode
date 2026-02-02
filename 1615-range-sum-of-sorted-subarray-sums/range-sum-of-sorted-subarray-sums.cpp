class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;

        vector<long long> allSums;

        // brute force subarray sums
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                allSums.push_back(sum);
            }
        }


        sort(allSums.begin(), allSums.end());

        vector<long long> prefix(allSums.size());
        prefix[0] = allSums[0];
        for (int i = 1; i < allSums.size(); i++) {
            prefix[i] = (prefix[i - 1] + allSums[i]) % MOD;
        }

        long long result;
        if (left == 1)
            result = prefix[right - 1];
        else
            result = (prefix[right - 1] - prefix[left - 2] + MOD) % MOD;

        return result;
    }
};
