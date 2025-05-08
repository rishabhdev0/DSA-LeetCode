class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int start = -1;
        int prev = -1;
        int result = 0;
        for(int i = 0 ; i<n;i++){
            if(nums[i]>right){
                // reset position 
                start = i; // position of the break point in array 
                prev = i;
            }
            else if(nums[i]>=left){
                // storing atleasst one element ending at ith pos
                prev = i;
            }
            result +=prev - start;
        }
        return result;
    }
};