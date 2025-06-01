class Solution {
private:
    int find_pivot(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }

    int binary_search(int left, int right, vector<int>& nums, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int pivot_index = find_pivot(nums);

        // Search in left half
        int left_result = binary_search(0, pivot_index - 1, nums, target);
        if (left_result != -1) {
            return left_result;
        }

        // Search in right half
        return binary_search(pivot_index, n - 1, nums, target);
    }
};
