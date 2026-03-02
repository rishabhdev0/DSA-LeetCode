class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long Totalsum = accumulate(nums.begin(), nums.end(), 0LL);
        int target = Totalsum % p;
        if (target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long sum = 0;
        int result = n;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum % p;

            int need = (mod - target + p) % p;

            if (mp.find(need) != mp.end()) {
                result = min(result, i - mp[need]);
            }

            mp[mod] = i; 
        }

        return result == n ? -1 : result;
    }
};