class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int k = n - 1;
        int i = 0;
        int j = n - 1;

        while (i <= j) {
            int i_ = nums[i] * nums[i];
            int j_ = nums[j] * nums[j];

            if (i_ > j_) {
                result[k--] = i_;
                i++;
            }
            else {
                result[k--] = j_;
                j--;
            }
        }

        return result;
    }
};