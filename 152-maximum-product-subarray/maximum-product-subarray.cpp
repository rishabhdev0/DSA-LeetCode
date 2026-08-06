class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int  result = nums[0];
        int leftProd = 1;
        int rightProd = 1;

        for(int i = 0 ; i < n ; i++){
            leftProd = leftProd == 0 ? 1 : leftProd;
            rightProd = rightProd == 0 ? 1 : rightProd;

            leftProd *= nums[i];
            rightProd *= nums[n-i-1];

            result = max({result , leftProd , rightProd});
        }
        return result;
    }
};