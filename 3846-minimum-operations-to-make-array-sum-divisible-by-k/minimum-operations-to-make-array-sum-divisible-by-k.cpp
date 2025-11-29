class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        int remainder = total_sum % k;
        return remainder;
    }
};