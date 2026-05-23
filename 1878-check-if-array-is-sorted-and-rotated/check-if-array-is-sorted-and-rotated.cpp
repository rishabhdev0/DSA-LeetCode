class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int spike = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                spike++;
            }
        }

        if(nums[0] < nums[n - 1]) {
            spike++;
        }

        return spike <= 1;
    }
};