class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int move_count = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] <= nums[i-1]){
                int new_num = nums[i - 1] + 1;
                move_count +=  new_num -nums[i];
                nums[i] = new_num; 
            }
        }
        return move_count;
    }
};