class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int max_total = 0;
        int min = *min_element(nums.begin() , nums.end());
        int max = *max_element(nums.begin() , nums.end());
        return (long long)k * (max - min);
    }
};