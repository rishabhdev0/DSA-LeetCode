class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int min_Len = n;

        int total = accumulate(nums.begin() , nums.end() , 0);
        if(total < target) return 0;


        while(j < n){
            sum += nums[j];
            while(sum >= target){
                min_Len = min(min_Len , j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return min_Len;
    }
};