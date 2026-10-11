class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        long long squaredSum = 0;
        for(int i = 1 ; i <= n ; i++){
            if(n % i == 0){
                squaredSum += nums[i - 1] * nums[i - 1];
            }
        }
        return squaredSum;
    }
};