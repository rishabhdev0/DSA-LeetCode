class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;
    
    void solve(vector<int>& nums, int start) {
        // Add the current subset at every step
        result.push_back(temp);
        
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(nums, i + 1);  // move and call to the next index recursion
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return result;
    }
};