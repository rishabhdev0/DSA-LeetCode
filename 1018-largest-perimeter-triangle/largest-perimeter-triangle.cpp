class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
       // sort in descending order;
        sort(nums.rbegin(), nums.rend());
        
        // Check consecutive triplets 
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        return 0; // No valid triangle found
    }
};