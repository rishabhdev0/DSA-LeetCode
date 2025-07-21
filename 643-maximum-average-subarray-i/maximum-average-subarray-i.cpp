class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        double max_avg = -1e9;

        while (j < n) {
            sum += nums[j];

            if (j - i + 1 == k) {
                double average = (double)sum / k;
                max_avg = max(max_avg, average);

                sum -= nums[i];
                i++;
            }

            j++;
        }

        return max_avg;
    }
};
