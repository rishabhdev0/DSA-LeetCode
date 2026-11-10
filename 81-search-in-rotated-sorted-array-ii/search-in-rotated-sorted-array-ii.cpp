class Solution {
public:
    int find_pivot(vector<int>& nums, int start, int end) {
        // skip duplicates on both ends
        while (start < end && nums[start] == nums[start + 1]) start++;
        while (start < end && nums[end] == nums[end - 1]) end--;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[mid + 1]) return mid + 1;

            if (nums[mid] < nums[end]) end = mid;
            else start = mid + 1;
        }

        return start;
    }

    bool binary_Search(vector<int>& nums, int target, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return true;

            if (nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;

        int p = find_pivot(nums, 0, n - 1);

        return binary_Search(nums, target, 0, p - 1) ||
               binary_Search(nums, target, p, n - 1);
    }
};