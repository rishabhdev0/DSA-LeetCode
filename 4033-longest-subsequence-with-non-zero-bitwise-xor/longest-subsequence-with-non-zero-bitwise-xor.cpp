class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        int zeroCount = 0;

        for(int num : nums){
            xr = xr ^ num;
            if(num == 0){
                zeroCount++;
            }
        }
        if(zeroCount == n){
            return 0;
        }
        if(xr != 0){
            return n;
        }
        return n - 1;
    }
};