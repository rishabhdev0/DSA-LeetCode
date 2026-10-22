class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool asc = true, desc = true;
        for (int i = 0; i < n; i++) {
            int next = nums[(i + 1) % n];
            if (next != (nums[i] + 1) % n) asc = false;
            if (next != (nums[i] - 1 + n) % n) desc = false;
        }

        if (asc) {
             int k = nums[0];
            if (k == 0) return 0;
            return min(n - k, k + 2); // rotate only || reverse + rotate + reverse
        }

        if (desc) {
            int leftRot  = n - nums.back() + 1;  // reverse, then rotate
            int rightRot = (nums[0] + 1) % n + 1; // rotate, then reverse
            return min(leftRot, rightRot);
        }

        return -1;
    }
};