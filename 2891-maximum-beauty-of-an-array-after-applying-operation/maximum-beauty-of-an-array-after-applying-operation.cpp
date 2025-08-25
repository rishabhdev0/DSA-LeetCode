class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n =  nums.size();
        int max_size = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            while(nums[j] - nums[i] > 2*k ){ // one for add and one for sub
                i++;
            }
            j++;
            max_size = max(max_size , j - i);
        }
        return max_size;
    }
};