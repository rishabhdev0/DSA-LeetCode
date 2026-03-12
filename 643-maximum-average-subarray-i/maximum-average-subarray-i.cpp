class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        double max_average = INT_MIN;
        int i = 0;
        int j = 0;
        while(j < n){
            sum += nums[j];
            if(j -  i + 1 == k){
                double average = double(sum) / k;
                max_average = max(max_average , average);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return max_average;
    }
};