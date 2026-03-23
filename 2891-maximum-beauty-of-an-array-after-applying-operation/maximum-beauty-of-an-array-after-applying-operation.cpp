class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            while(nums[j] - nums[i] > 2 * k){
                i++;
            }
            j++;
            count = max(count , j - i );
        }
        return count;
    }
};