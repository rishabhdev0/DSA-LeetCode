class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums[n-1] - nums[0];
        
        // Binary search on possible distance values
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Two-pointer technique to count pairs with distance <= mid
            int count = 0;
            int j = 0;
            for (int i = 0; i < n; i++) {
                // Move j forward until nums[j] - nums[i] > mid
                while (j < n && nums[j] - nums[i] <= mid) {
                    j++;
                }
                // All pairs (i, j-1), (i, j-2), ..., (i, i+1) satisfy the condition
                count += j - i - 1;
            }
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};