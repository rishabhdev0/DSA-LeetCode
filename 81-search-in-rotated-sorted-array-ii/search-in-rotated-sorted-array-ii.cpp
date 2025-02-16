class Solution {
private:
    int find_pivot(vector<int>& nums, int n) {
        int l = 0;
        int r = n - 1;
        while (l < r) {
            // Skip duplicates from the left
            while (l < r && nums[l] == nums[l + 1]) l++;
            // Skip duplicates from the right
            while (l < r && nums[r] == nums[r - 1]) r--;
            
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1; // The pivot is on the right side
            } else {
                r = mid; // The pivot is on the left side (including mid)
            }
        }
        return r; // Return the pivot index
    }

    int binarySearch(int l, int r, vector<int>& nums, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] > target) {
                r = mid - 1; // Search the left half
            } else {
                l = mid + 1; // Search the right half
            }
        }
        return -1; // Target not found
    }

public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false; // Edge case

        int pivot_index = find_pivot(nums, n); 

        // Search in the left subarray (from 0 to pivot_index - 1)
        int left_search = binarySearch(0, pivot_index - 1, nums, target);
        if (left_search != -1) {
            return true; // Target found in the left subarray
        }

        // Search in the right subarray (from pivot_index to n - 1)
        int right_search = binarySearch(pivot_index, n - 1, nums, target);
        return right_search != -1; // Return true if target found in the right subarray
    }
};