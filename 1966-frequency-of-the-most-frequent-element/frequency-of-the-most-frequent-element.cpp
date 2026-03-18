class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        long long sum = 0;
        int i = 0;
        int j = 0;
        int max_freq = 1;
        while(j < n){
            sum += nums[j];
            while((long long)nums[j] * (j - i+ 1) - sum > k){
                sum -= nums[i];
                i++;
            }
            max_freq = max(max_freq , j - i + 1);
            j++;
        }
        return max_freq;
    }
};