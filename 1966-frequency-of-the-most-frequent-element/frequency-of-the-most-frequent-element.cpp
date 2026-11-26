class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 1;
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            sum += nums[j];

            while((long long)nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};