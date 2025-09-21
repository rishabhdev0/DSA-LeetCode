class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>original(nums);
        sort(nums.begin(),nums.end());
        if(original==nums) return 0;
        int i = 0;
        int j = n-1;
        while(i<n && original[i]==nums[i])i++;
        while(j>=0 && original[j]==nums[j]) j--;
        return j-i+1;
    }
};