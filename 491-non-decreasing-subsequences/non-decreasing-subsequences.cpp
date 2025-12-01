class Solution {
public:
    vector<vector<int>> result;
    vector<int> curr;
    
    void backtracking(vector<int>& nums, int idx) {
        if(curr.size() >= 2) {
            result.push_back(curr);
        }
        
        unordered_set<int> used;  
        
        for(int i = idx; i < nums.size(); i++) {
            if(used.find(nums[i]) != used.end()) {
                continue;
            }
            
            if(curr.empty() || nums[i] >= curr.back()) {
                used.insert(nums[i]); 
                curr.push_back(nums[i]);
                backtracking(nums, i + 1); 
                curr.pop_back();
             // we don't remove from used set here because we need to prevent duplicates
             // at the same level across different branches
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};