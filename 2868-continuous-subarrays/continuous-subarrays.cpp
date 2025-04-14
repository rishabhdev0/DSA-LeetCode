class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        int i = 0;
        long long count = 0;
        
        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;
            
            // Calculate current max - min
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                mp[nums[i]]--; // we will remove the ith element and now shrink
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            count += j - i + 1;
        }
        
        return count;
    }
};