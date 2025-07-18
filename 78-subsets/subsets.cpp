class Solution {
private:
    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int> temp, int idx) {
        if (idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        // do not pick current element
        backtracking(nums, result, temp, idx + 1);

        // pick current element
        temp.push_back(nums[idx]); 
        backtracking(nums, result, temp, idx + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> temp;
        int index = 0;
        backtracking(nums, result, temp, index);
        return result;
    }
};
