class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        double maxAverage = INT_MIN; 
        double sum = 0;
        while (j < nums.size()) {
            sum += nums[j];

            if (j - i + 1 < k) {
                j++; 
            } else if (j - i + 1 == k) {
                double currentAverage = sum / k;
                maxAverage = max(maxAverage, currentAverage); 
                sum -= nums[i]; 
                i++;
                j++;
            }
        }

        return maxAverage;
    }
};