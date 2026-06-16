class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());

        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;

        while (k >= 0) {
            int start = nums[i] * nums[i];
            int end = nums[j] * nums[j];

            if (start > end) {
                result[k] = start;
                i++;
            } else {
                result[k] = end;
                j--;
            }

            k--;
        }

        return result;
    }
};