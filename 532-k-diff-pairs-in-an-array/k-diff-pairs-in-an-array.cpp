class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int i = 0;
        int j = 1;
        int pair_count  = 0;
        while(j < n){
            int diff = nums[j] - nums[i];

            if(diff == k){
                pair_count++;
                i++;
                j++;
                while(i < n && nums[i]==nums[i-1]) i++;
                while(j <  n &&  nums[j] == nums[j-1]) j++;
            }
            else if(diff > k) i++;
            else j++;
            if(i==j) j++;
        }
        return pair_count;
    }
};