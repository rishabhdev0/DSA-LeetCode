class Solution {
public:
    int dp[100001][2];
    int n;
   
   int solve(vector<int>& nums1 , vector<int>& nums2 , int idx , int prevswap){
       if(idx >= n) return 0;

       if(dp[idx][prevswap] != -1){
        return dp[idx][prevswap];
       }

       int answer = INT_MAX;

       if(idx == 0){ // no previous element
          int skip = solve(nums1 , nums2 , idx + 1 , 0);
          int take = 1 + solve(nums1 , nums2 , idx + 1 , 1);
          answer = min(skip , take);
          return dp[idx][prevswap] = answer;
       }

       int prev_1 = nums1[idx - 1];
       int prev_2 = nums2[idx - 1];

       if(prevswap){
        swap(prev_1 , prev_2);
       }

       if(nums1[idx] > prev_1 && nums2[idx] > prev_2){
           int skip  = solve(nums1 , nums2 , idx + 1 , 0);
          answer = min(answer , skip);
       }


       if(nums2[idx] > prev_1 && nums1[idx] > prev_2){
           int take = 1 + solve(nums1 , nums2 , idx + 1 , 1);
           answer = min(answer , take);
       }
    
       return dp[idx][prevswap] = answer;
   }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(dp , -1 , sizeof(dp));
        return solve(nums1 , nums2 , 0 , 0);
    }
};