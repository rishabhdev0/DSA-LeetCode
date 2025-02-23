class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int last_zeros=-1;
        int result=0;
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]==0){
               i=last_zeros+1;
                last_zeros=j;
            }
            result=max(result,j-i);
            j++;
        }
        return result;
    }
};