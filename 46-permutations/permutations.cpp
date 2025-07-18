class Solution {
private:
    void backtracking(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, unordered_set<int>& used) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used.find(nums[i]) == used.end()) { //check if element present in set
                temp.push_back(nums[i]);           //or not
                used.insert(nums[i]);
                backtracking(nums, temp, result, used);
                temp.pop_back();
                used.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        unordered_set<int> used;
        backtracking(nums, temp, result, used);
        return result;
    }
};
