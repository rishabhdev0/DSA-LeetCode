class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>SortedNums = nums;
        sort(SortedNums.begin() , SortedNums.end());
        vector<int>result(n);
        for(int i = 0 ; i < n ; i++){
           auto it = lower_bound(SortedNums.begin() , SortedNums.end() , nums[i]);
           result[i] = distance(SortedNums.begin() , it);
        }
        return result;
    }
};