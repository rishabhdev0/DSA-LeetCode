class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int>dp(n , 1);
        vector<int>parent(n , -1);
        int max_size = 1;
        int lastindex = 0;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if(dp[i] > max_size){
                max_size = dp[i];
                lastindex = i;
            }
        }
        vector<int>result;
        while(lastindex != -1){
            result.push_back(nums[lastindex]);
            lastindex = parent[lastindex];
        }
        return result;
    }
};