class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>freq;
        freq[0] = 1;
        long long sum = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int mod = ((sum % k) + k) % k;
            if(freq.find(mod) != freq.end()){
                 count += freq[mod];
            }
            freq[mod]++;
        }
        return count;
    }
};