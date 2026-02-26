class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int sumWithoutZero = 1;
        int zeroCount = 0;
        for(int num : nums){
            if(num == 0){
                zeroCount++;
            }else{
                sumWithoutZero *= num;
            }
        }
        vector<int>result(n , 0);
        for(int i = 0 ; i < n ; i++){
            if(zeroCount > 1){
                result[i] = 0;
            }else if(zeroCount == 1){
                result [i] = (nums[i] == 0 ? sumWithoutZero : 0);
            }else{
                result[i] = sumWithoutZero / nums[i];
            }
        }
        return result;
    }
};