class Solution {
private:
    int pivotIndex(vector<int>& nums, int n) {
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1; // right be answer milega 
            } else {
                r = mid; // mid bhi sabse chota element ho sakta hai   
            }
        }
        return r;
    }

    int binarySearch(int l, int r, vector<int>& nums, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1; // Edge case

        int pivot_index = pivotIndex(nums, n);//chota element search karo

        // applying binary search on both left and right side 
        // left side me search hoga
        int left_result = binarySearch(0, pivot_index - 1, nums, target);
        if (left_result != -1) {
            return left_result;
        }

        // right side me search karenge
        int right_result = binarySearch(pivot_index, n - 1, nums, target);
        return right_result;
    }
};