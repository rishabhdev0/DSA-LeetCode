class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int , int>freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<int>unique;
        for(auto &it : freq){
            unique.push_back(it.first);
        }
        sort(unique.begin() , unique.end());
        
        int n = unique.size();
        vector<int>dp(n , 0);
        dp[0] = unique[0] * freq[unique[0]];
        for(int i = 1 ; i < n ; i++){
            long long val = unique[i] * freq[unique[i]];
            if(unique[i] == unique[i-1] + 1){
                int take = val + (i > 1 ? dp[i-2] : 0);
                int skip = dp[i-1];
                dp[i] = max(take , skip);
            }else{
                dp[i] = dp[i-1] + val;
            }
        }
        return dp[n-1];
    }
};