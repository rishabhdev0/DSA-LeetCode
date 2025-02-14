class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
       int sumClosest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        for (int k = 0; k <= n - 3; k++) {
            int i = k + 1;
            int j = n - 1;
            
            while (i < j) {  
                int sum = nums[k] + nums[i] + nums[j];
                
                if (abs(target - sum) < abs(target - sumClosest)) {
                    sumClosest = sum;
                }
                
                if (sum < target) {
                    i++;  
                } else if (sum > target) {
                    j--;  
                } else {
                    return sum;
                }
            }
        }
        return sumClosest;
    }
};
