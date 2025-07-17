class Solution {
private:
    void solve(vector<int>& candidates, int target, int idx, vector<vector<int>>& result, vector<int>& temp, int sum) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (sum > target) return;

        for (int i = idx; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            solve(candidates, target, i, result, temp, sum + candidates[i]); 
            temp.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(candidates, target, 0, result, temp, 0);
        return result;
    }
};
