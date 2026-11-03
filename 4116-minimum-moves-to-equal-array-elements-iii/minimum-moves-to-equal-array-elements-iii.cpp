class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max_Ele = *max_element(nums.begin() , nums.end());
        long long count = 0;
        for(int i = 0 ; i < n ; i++){
            count += max_Ele - nums[i];
        }
        return count;
    }
};