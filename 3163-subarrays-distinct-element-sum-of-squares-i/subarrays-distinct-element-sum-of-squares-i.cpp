class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        for(int i = 0 ; i < n ; i++){
           unordered_set<int>seen;
            for(int j = i ; j < n ; j++){
                seen.insert(nums[j]);
                result += seen.size() * seen.size();
            }
        }
        return result;
    }
};