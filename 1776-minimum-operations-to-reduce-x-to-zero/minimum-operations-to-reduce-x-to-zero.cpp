class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = accumulate(nums.begin() , nums.end() , 0LL);
        int target =  total - x;
        if(target < 0) return -1;
        if(target == 0) return n;

        int curr_sum = 0;
        int min_len = -1;
        int i = 0;
        int j = 0;
        while(j < n){
            curr_sum += nums[j];
            while(curr_sum > target){
                curr_sum -= nums[i];
                i++;
            }
            if(curr_sum == target){
                min_len = max(min_len , j - i + 1);
            }
            j++;
        }
        return min_len == -1 ? -1 : n - min_len;
    }
};