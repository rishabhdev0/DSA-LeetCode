class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n - 1;
        int result = 0;
        const int MOD = 1e9 + 7;
        
        // Precompute powers of 2 modulo MOD
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                result = (result + power[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};