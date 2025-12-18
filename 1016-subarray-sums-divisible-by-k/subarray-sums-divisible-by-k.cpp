class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // {mod -> freq}
        mp[0] = 1;

        int count = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = ((sum % k) + k) % k;

            if (mp.find(mod) != mp.end()) {
                count += mp[mod];
            }
            mp[mod]++;
        }
        return count;
    }
};
