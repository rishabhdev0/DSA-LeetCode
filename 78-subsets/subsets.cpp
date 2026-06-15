class Solution {
public:
    vector<int>temp;
    vector<vector<int>>result;

    void backtracking(vector<int>& nums , int idx){
        result.push_back(temp);

        for(int i = idx ; i < nums.size() ; i++){
            temp.push_back(nums[i]);
            backtracking(nums , i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums , 0);
        return result;
    }
};