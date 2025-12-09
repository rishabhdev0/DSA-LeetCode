class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> left_map;
        unordered_map<int, int> right_map;
        int mod = 1e9 + 7;
        int count = 0;
        
        for(int num : nums) {
            right_map[num]++;
        }
        
        for(int i = 0; i < n; i++) {
            right_map[nums[i]]--;

            int left = left_map[nums[i] * 2];
            int right = right_map[nums[i] * 2];

           count = ( count + (1LL * left * right)) % mod;

            left_map[nums[i]]++;
        }
        
        return  count;
    }
};