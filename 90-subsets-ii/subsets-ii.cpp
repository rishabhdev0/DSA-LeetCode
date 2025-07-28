class Solution {
public:
    vector<vector<int>> result;

    void backtracking(vector<int>& nums, vector<int>& temp, int idx) {
        result.push_back(temp); 

        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            backtracking(nums, temp, i + 1); 
            temp.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> temp;
        backtracking(nums, temp, 0);
        return result;
    }
};
