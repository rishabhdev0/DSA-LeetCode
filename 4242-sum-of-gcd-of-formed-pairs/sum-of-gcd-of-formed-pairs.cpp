class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        vector<int> gcd_prefix(n);

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            gcd_prefix[i] = __gcd(maxi, nums[i]);
        }

        sort(gcd_prefix.begin(), gcd_prefix.end());

        int i = 0;
        int j = n - 1;
        long long sum = 0;

        while (i < j) {
            sum += __gcd(gcd_prefix[i], gcd_prefix[j]);
            i++;
            j--;
        }

        return sum;
    }
};