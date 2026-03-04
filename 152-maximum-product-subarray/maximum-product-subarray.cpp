class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];
        for(int i = 1 ; i < n ;  i++){
            int curr = nums[i];
            int prevMax = maxProd;
           int prevMin = minProd;
           maxProd = max({curr , prevMax * curr , prevMin * curr});
           minProd = min({curr , prevMax * curr , prevMin * curr});
           result = max(result , maxProd);
        }
        return result;
    }
};