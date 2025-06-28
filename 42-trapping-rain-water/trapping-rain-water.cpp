class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0;
        int right = n - 1;
        int maxLeftHeight = height[left];
        int maxRightHeight = height[right];
        int totalWaterTrapped = 0;

        while (left < right) {
            if (maxLeftHeight < maxRightHeight) {
                left++;
                maxLeftHeight = max(maxLeftHeight, height[left]);
                int waterAtCurrentBar = maxLeftHeight - height[left];
                totalWaterTrapped += waterAtCurrentBar;
            } else {
                right--;
                maxRightHeight = max(maxRightHeight, height[right]);
                int waterAtCurrentBar = maxRightHeight - height[right];
                totalWaterTrapped += waterAtCurrentBar;
            }
        }

        return totalWaterTrapped;
    }
};
