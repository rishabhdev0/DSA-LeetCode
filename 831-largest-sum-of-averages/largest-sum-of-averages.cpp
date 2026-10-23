class Solution {
public:
    int n;
    double dp[101][101];

    double solve(vector<int>& nums , int k , int idx){
        if(k == 1){
            double s = 0;
            for(int i = idx ; i < n ; i++) s += nums[i];
            return s / (n - idx);
        }

        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        double answer = 0;
        double sum = 0;

        for(int i = idx ; i <= n - k ; i++){
            sum += nums[i];
            double average = sum / (i - idx + 1);
            answer = max(answer, average + solve(nums , k - 1 , i + 1));
        }
        return dp[idx][k] = answer;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        for(int i = 0 ; i < 101 ; i++)
            for(int j = 0 ; j < 101 ; j++)
                dp[i][j] = -1;
        return solve(nums , k , 0);
    }
};