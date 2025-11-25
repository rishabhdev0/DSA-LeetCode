class Solution {
private:
    void backtracking(vector<int>& candidates, int target, int sum, int idx, 
                      vector<int>& temp, vector<vector<int>>& result, vector<bool>& visited) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (sum > target) return;

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) continue;
            if (visited[i]) continue;

            visited[i] = true;
            temp.push_back(candidates[i]);

            backtracking(candidates, target, sum + candidates[i], i + 1, temp, result, visited);

            visited[i] = false;
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // to group duplicates
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(candidates.size(), false);

        backtracking(candidates, target, 0, 0, temp, result, visited);
        return result;
    }
};
