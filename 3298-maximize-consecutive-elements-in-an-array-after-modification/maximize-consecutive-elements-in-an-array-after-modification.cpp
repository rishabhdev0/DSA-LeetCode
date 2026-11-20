class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int find(int idx, vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin() + idx, nums.end(), target) - nums.begin();

        if (lb < n && nums[lb] == target) return lb;

        return -1;
    }

    int solve(int idx, int inc, vector<int>& nums) {

        if (memo[idx][inc] != -1) {
            return memo[idx][inc];
        }

        int curr = nums[idx] + inc;
        int len = 1;

        // Option 1: Find the next element equal to curr + 1
        int j = find(idx + 1, nums, curr + 1);

        if (j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }

        // Option 2: Increment the next element equal to curr
        j = find(idx + 1, nums, curr);

        if (j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[idx][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        memo.assign(n, vector<int>(2, -1));

        int result = 0;

        for (int i = 0; i < n; i++) {
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return result;
    }
};
