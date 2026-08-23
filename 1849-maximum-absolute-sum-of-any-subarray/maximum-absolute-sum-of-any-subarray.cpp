class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum =0;
        int maxSum = 0;
        int sum = 0;
        for(int num : nums){
            sum += num;
            minSum = min(minSum , sum);
            maxSum = max(maxSum , sum);
        }
        return maxSum - minSum;
    }
};