class Solution {
public:
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        if(index >= nums.size()) {
            ans.push_back(output);  
            return;
        }
        
        // Exclude current element
        solve(nums, output, index + 1, ans);
        
        // Include current element
        output.push_back(nums[index]);
        solve(nums, output, index + 1, ans);
        
        
        output.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};
