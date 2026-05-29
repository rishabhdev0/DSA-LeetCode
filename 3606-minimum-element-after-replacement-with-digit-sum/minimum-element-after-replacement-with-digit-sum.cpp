class Solution {
public:
    int DigitSum(int num) {
        int sum = 0;

        while (num != 0) {
            int digit = num % 10;
            sum = sum + digit;
            num /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = DigitSum(nums[i]);
        }

        int result = *min_element(nums.begin(), nums.end());
        return result;
    }
};