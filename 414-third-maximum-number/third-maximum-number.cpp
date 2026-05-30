class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin() , nums.rend());
        int count = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] != nums[i-1]){
                count++;
                if(count == 3){
                    return nums[i];
                }
            }
        }
        return nums[0];
    }
};