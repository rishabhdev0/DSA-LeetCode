class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(candidates, target, 0, 0, temp, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, int currentSum, 
                   vector<int>& temp, vector<vector<int>>& result) {
        // Base case: if current sum equals target, we found a valid combination
        if (currentSum == target) {
            result.push_back(temp);
            return;
        }
        
        if (currentSum > target) {
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            currentSum += candidates[i];
            
            backtrack(candidates, target, i, currentSum, temp, result);
            
            currentSum -= candidates[i];
            temp.pop_back();
        }
    }
};