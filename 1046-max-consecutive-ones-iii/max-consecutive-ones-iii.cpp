class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int max_Ones = 0;
        int i = 0;
        int j = 0;
        int flipCount = 0;
        while(j <  n){
            if(nums[j] == 0){
                flipCount++;
            }
            while(flipCount > k){
                if(nums[i] == 0){
                    flipCount--;
                }
                i++;
            }
            max_Ones = max(max_Ones , j - i + 1);
            j++;
        }
        return max_Ones;
    }
};