class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currSum = 0;
        int maxSum = INT_MIN;
        int currMin = 0;
        int minSum = INT_MAX;

        for(int i = 0 ; i <  nums.size() ; i++){
            currSum = max(nums[i] , nums[i] + currSum);
            maxSum = max(maxSum , currSum);

            // now the most important part : how we are getting the minSum value in the middle
            currMin = min(nums[i] , currMin + nums[i]);
            minSum = min(minSum , currMin);

            totalSum += nums[i];

        }
         if(maxSum < 0){
                return maxSum;
            }
        return max(maxSum , totalSum - minSum);
    }
};