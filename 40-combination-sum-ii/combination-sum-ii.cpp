class Solution {
private:
    void recursion(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> output, int index) {
        if(target == 0) {
            ans.push_back(output);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;  

            output.push_back(candidates[i]);
            recursion(candidates, target - candidates[i], ans, output, i + 1);  
            output.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> output;
        recursion(candidates, target, ans, output, 0);
        return ans;
    }
};
