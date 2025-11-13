class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mid % 2 == 1) mid--; // we always check even indices
            
            // If pairs match, single element is to the right
            if (nums[mid] == nums[mid + 1]) {
                start = mid + 2;
            } else {
                // Single element is at mid or to the left
                end = mid;
            }
        }
        
        return nums[start];
    }
};