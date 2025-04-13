class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int result=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                k--;
            }
            while(k < 0){
                if(nums[i]==0){
                    k++;
                }
                   i++;
            }
            result = max(result,j-i+1);
        }
        return result;
    }
};