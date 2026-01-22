class Solution {
public:
    int findMinSum(vector<int>& nums){
        int pair = -1;
        int Minsum = INT_MAX;
        for(int i = 0 ; i < nums.size() - 1; i++){
            int sum = nums[i] + nums[i+1];
            if(sum < Minsum){
                pair = i;
                Minsum = sum;
            }
        }
        return pair;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin() , nums.end())){
            int idx =  findMinSum(nums);
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(begin(nums) +  idx + 1);
            ops++;
        }
        return ops;
    }
};