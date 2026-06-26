class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int>mp;
        mp[0] = 1;

        int i = 0;
        int validPoint = 0;
        long long count = 0;
        int cumSum = 0;

        while(i < n){
            if(nums[i] == target){
                validPoint += mp[cumSum];
                cumSum += 1;
            }else{
                cumSum -= 1;
                validPoint -= mp[cumSum];
            }
            mp[cumSum]++;
            count += validPoint;
            i++;
        }
        return count;
    }
};