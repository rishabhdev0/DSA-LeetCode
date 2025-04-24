class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted(nums);
        sort(sorted.begin(),sorted.end());
        if(sorted == nums) return 0;
        int i = 0 ;
        int j = n-1;
            while(i<n && sorted[i]==nums[i]){
                i++;
            }
            while(j>=0 && sorted[j]==nums[j]){
                j--;
            }
        return j-i+1;
    }
};