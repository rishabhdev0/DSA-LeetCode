class Solution {
private:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& result) {
        if (idx >= nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);         // do
            solve(nums, idx + 1, result);     // explore
            swap(nums[idx], nums[i]);         // undo (backtrack)
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, 0, result);
        return result;
    }
};