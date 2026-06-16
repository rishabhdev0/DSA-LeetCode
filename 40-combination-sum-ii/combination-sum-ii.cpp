class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void backtracking(vector<int>& nums, int idx, int target) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            backtracking(nums, i + 1, target - nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, target);
        return result;
    }
};