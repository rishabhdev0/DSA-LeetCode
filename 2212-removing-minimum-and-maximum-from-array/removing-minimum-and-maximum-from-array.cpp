class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }

        int siz = nums.size();
        int n = siz / 2;

        int left = -1, right = -1;

        for (int i = 0; i < siz; i++) {
            if (nums[i] == mini || nums[i] == maxi) {
                if (left == -1)
                    left = i;
                right = i;
            }
        }

        int count1 = right + 1;       // both from left
        int count2 = siz - left;     // both from right
        int count3 = (left + 1) + (siz - right); // one each side

        return min({count1, count2, count3});
    }
};