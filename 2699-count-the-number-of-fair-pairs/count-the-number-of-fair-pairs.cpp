class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
           
            int left = manual_lower_bound(nums, i + 1, n, lower - nums[i]);
            int right = manual_upper_bound(nums, i + 1, n, upper - nums[i]);
            count += (right - left);
        }

        return count;
    }

private:
    int manual_lower_bound(const std::vector<int>& nums, int start, int end, int target) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int manual_upper_bound(const std::vector<int>& nums, int start, int end, int target) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};