// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>original(nums);
//         sort(nums.begin(),nums.end());
//         if(original==nums) return 0;
//         int i = 0;
//         int j = n-1;
//         while(i<n && original[i]==nums[i])i++;
//         while(j>=0 && original[j]==nums[j]) j--;
//         return j-i+1;
//     }
// };


// using 0(n) + constandt space;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int left = -1, right = -1;
        int max_seen = nums[0];
        int min_seen = nums[n - 1];

        // Left to right → find right boundary
        for (int i = 1; i < n; i++) {
            max_seen = max(max_seen , nums[i]);
            if (nums[i] < max_seen) {
                right = i;
            } 
        }

        // Right to left → find left boundary
        for (int i = n - 2; i >= 0; i--) {
            min_seen = min(min_seen , nums[i]);
            if (nums[i] > min_seen) {
                left = i;
            } 
        }

        if (right == -1) return 0;
        return right - left + 1;
    }
};