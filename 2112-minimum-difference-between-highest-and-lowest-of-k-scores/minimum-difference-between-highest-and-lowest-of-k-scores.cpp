class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k == 1) return 0;

        sort(nums.begin(), nums.end());  // Must sort

        int i = 0;
        int j = 0;
        int min_diff = INT_MAX;

        while (j < n) {
            if (j - i + 1 == k) { 
                int diff = nums[j]-nums[i];
                min_diff = min(min_diff, diff);
                i++;
                j++;
            } else j++;
        }

        return min_diff;
    }
};
