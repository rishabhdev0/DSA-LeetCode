class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        long long divisible = 0;
        for(int num : nums){
            if(num % 3 == 0){
                divisible++;
            }
        }
        return n - divisible ;
    }
};