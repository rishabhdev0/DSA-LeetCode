class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j  = 0;
        int lastValid = -1;
        while(j < n){
            if(nums[j] > right){
                lastValid = -1;
                i = j + 1;
            }else if (nums[j] >= left){
               lastValid = j;
            }
            if (lastValid != -1){
                count+=(lastValid - i + 1);
            }
            j++; 
        }
        return count;
    }
};