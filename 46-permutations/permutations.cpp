class Solution {
public:
    vector<vector<int>> result;

    void backtracking(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);

            backtracking(nums, idx + 1);

            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};