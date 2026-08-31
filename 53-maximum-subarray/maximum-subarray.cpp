class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = INT_MIN;
        int curr  = 0;
        for(int num : nums){
            curr = max(curr + num , num);
            max_sub = max(max_sub , curr);
        }
        return max_sub;
    }
};