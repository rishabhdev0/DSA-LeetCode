class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Positive → not seen
        // Negative → seen before
        int n = nums.size();
        vector<int>result;
        for(int i = 0 ; i < n ; i++){
           int idx = abs(nums[i]) - 1;
           if(nums[idx] < 0){
                 result.push_back(abs(nums[i]));
           }else{
              nums[idx] *= -1;
           }
        }
        return result;
    }
};