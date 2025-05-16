class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n - 1;
        int pair_count = 0;

        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < target) {
                pair_count += (j - i); // since all element are small we will do (j-i);
                i++; // for finding more new pair 
            } else {
                j--; // in search of smaller sum 
            }
        }
        return pair_count;
    }
};
