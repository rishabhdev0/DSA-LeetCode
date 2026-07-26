class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        long long option = nums[0] * nums[1] * nums[n-1];
        long long option_2 = nums[n-1] * nums[n-2] * nums[n-3];
        return max(option , option_2);
    }
};