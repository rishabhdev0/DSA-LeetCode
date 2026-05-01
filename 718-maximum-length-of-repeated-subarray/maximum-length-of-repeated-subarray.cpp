class Solution {
public:
    int dp[1001][1001];
    int ans = 0;

    int solve(vector<int>& nums1 , vector<int>& nums2 , int i , int j){
        
        if(i == nums1.size() || j == nums2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int length = 0;

        if(nums1[i] == nums2[j]){
            length = 1 + solve(nums1 , nums2 , i + 1 , j + 1);
            ans = max(ans , length);
        }

        
        solve(nums1 , nums2 , i + 1 , j);
        solve(nums1 , nums2 , i , j + 1);

        return dp[i][j] = length;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp , -1 , sizeof(dp));
        solve(nums1 , nums2 , 0 , 0);
        return ans;
    }
};