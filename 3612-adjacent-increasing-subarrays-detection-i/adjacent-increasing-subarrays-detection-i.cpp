class Solution {
private:
    bool increasing(int start, vector<int>& nums, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i <= n - 2 * k; i++) {
            // Check if both subarrays [i, i+k-1] and [i+k, i+2k-1] are strictly increasing
            if (increasing(i, nums, k) && increasing(i + k, nums, k)) {
                return true;
            }
        }
        return false;
    }
};