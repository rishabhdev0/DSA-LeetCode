class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;

    void backtracking(vector<int>& candidates, int target, int idx, int sum) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (idx >= candidates.size() || sum > target) {
            return;
        }

        // Include the current element
        temp.push_back(candidates[idx]);
        backtracking(candidates, target, idx, sum + candidates[idx]);//same idx;
        temp.pop_back();

        // Exclude the current element
        backtracking(candidates, target, idx + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};