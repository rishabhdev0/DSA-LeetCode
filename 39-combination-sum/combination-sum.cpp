class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void backtracking(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);

            backtracking(candidates, target - candidates[i], i);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return result;
    }
};