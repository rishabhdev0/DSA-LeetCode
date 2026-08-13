class Solution {
public:
    int n;

    bool solve(vector<int>& nums, int k, int target,
               int idx, int sum, vector<bool>& used) {

        if(k == 0)
            return true;

        if(sum == target) {
            return solve(nums, k - 1, target, 0, 0, used);
        }

        for(int i = idx; i < n; i++) {

            if(!used[i] && sum + nums[i] <= target) {

                used[i] = true;

                if(solve(nums, k, target,
                         i + 1, sum + nums[i], used)) {
                    return true;
                }

                used[i] = false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum % k != 0)
            return false;

        int target = totalSum / k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0] > target)
            return false;

        vector<bool> used(n, false);

        return solve(nums, k, target, 0, 0, used);
    }
};