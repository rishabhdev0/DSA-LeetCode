class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mp; // -> {odd , freq};
        mp[0] = 1;
        int odd = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 1){
                odd++;
            }
            if(mp.find(odd- k) != mp.end()){
                count += mp[odd - k];
            }
            mp[odd]++;
        }
        return count;
    }
};