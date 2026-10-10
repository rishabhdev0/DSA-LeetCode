
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int currmin = nums[k];
        int result = nums[k];

        int i = k - 1;
        int j = k + 1;

        while (i >= 0 || j < n) {
            int leftval = (i >= 0) ? nums[i] : 0;
            int rightval = (j < n) ? nums[j] : 0;

            if (leftval > rightval) {
                currmin = min(currmin, nums[i]);
                i--;
            } else {
                currmin = min(currmin, nums[j]);
                j++;
            }

            result = max(result, currmin * (j - i - 1));
        }

        return result;
    }
};
