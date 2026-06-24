class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void backtracking(vector<int>& nums, int start) {
        if (temp.size() >= 2) {
            result.push_back(temp);
        }

        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;

            if (temp.empty() || nums[i] >= temp.back()) {
                used.insert(nums[i]);

                temp.push_back(nums[i]);
                backtracking(nums, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};