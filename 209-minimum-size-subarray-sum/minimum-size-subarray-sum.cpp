class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int i = 0;
        int mincount = INT_MAX;
        int sum_target = 0;
        while(j<n){
        sum_target += nums[j];
        while(sum_target >= target){
            mincount = min(mincount, j-i+1);
            sum_target-=nums[i];
            i++;
        }
        j++;
        }
        return mincount == INT_MAX ? 0 : mincount;
    }
};