class Solution {
private:
    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int idx, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            // Choose
            visited[i] = true;
            temp.push_back(nums[i]);

            // Explore
            backtracking(nums, result, temp, idx + 1, visited);

            // Undo
            visited[i] = false;
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end()); // to handle duplicates
        backtracking(nums, result, temp, 0, visited);
        return result;
    }
};
