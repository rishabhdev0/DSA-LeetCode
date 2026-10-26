class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int length = INT_MIN;
        int zero_count = 0;

        while(j < n){
             if(nums[j] == 0){
                zero_count++;
             }
             while(zero_count >  k){
                if(nums[i] == 0){
                    zero_count--;
                }
                i++;
             }
             length = max(length , j - i + 1);
             j++;
        }
        return length;
    }
};