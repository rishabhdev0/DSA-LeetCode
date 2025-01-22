class Solution {
public:
    void recursion(vector<int>& candidates, int target, int index, vector<vector<int>>& ans, vector<int>& output) {
        if (target == 0) {
            ans.push_back(output);  
            return;
        }
        
        if (index >= candidates.size()) {
            return;
        }

        recursion(candidates, target, index + 1, ans, output);

        if (candidates[index] <= target) {
            output.push_back(candidates[index]);  
            recursion(candidates, target - candidates[index], index, ans, output);  // 
            output.pop_back();  
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        recursion(candidates, target, index, ans, output);  // Start recursion
        return ans;
    }
};
