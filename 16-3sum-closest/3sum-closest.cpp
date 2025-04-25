class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sumClosest = nums[0] + nums[1] + nums[2]; 
        
        for (int k = 0; k < n - 2; k++) { 
            int i = k + 1;
            int j = n - 1;
            while (i < j) {
                int targetSum = nums[k] + nums[i] + nums[j];
                if (abs(target - targetSum) < abs(target - sumClosest)) { 
                    sumClosest = targetSum;
                }
                if (targetSum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return sumClosest;
    }
};