class Solution {
    bool isPossible(vector<int>& nums, int mid, int maxOperations) {
        int count = 0;
        for (int num : nums) {
            count += (num - 1) / mid; 
            if (count > maxOperations) return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, mid, maxOperations)) {
                right = mid; 
            } else {
                left = mid + 1;  
            }
        }

        return left;
    }
};
