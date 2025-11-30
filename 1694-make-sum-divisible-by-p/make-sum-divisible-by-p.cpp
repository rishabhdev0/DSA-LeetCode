class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums) {
            total += num;
        }
        
        // Find the remainder we need to remove
        int target_remainder = total % p;
        if (target_remainder == 0) {
            return 0;
        }
        
        // map -> {mod, indices};
        unordered_map<int, int> remainder_map;
        remainder_map[0] = -1; 
        
        long long prefix_sum = 0;
        int min_length = n; 
        
        for (int i = 0; i < n; i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            
            // Calculate the remainder we need to find in our map
            int needed_remainder = (prefix_sum - target_remainder + p) % p;
            
            // If we found the needed remainder in our map
            if (remainder_map.find(needed_remainder) != remainder_map.end()) {
                int subarray_length = i - remainder_map[needed_remainder];
                min_length = min(min_length, subarray_length);
            }
            
            // Store current prefix sum remainder with current index
            remainder_map[prefix_sum] = i;
        }
        
        return min_length < n ? min_length : -1;
    }
};