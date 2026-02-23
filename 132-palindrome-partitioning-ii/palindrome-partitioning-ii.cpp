class Solution {
public:
    bool isPalindrome(string &s , int i , int j){
       while(i <= j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
       return true;
    }
    int dp[2001][2001];
    int solve(string &s , int i , int j){
        if(i >= j) return 0;
        if(isPalindrome(s , i , j)) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int result = INT_MAX;
        // trying the every cut 
        for(int k = i ; k < j ; k++){
            if(isPalindrome(s, i  , k)){
                int temp = 1 + solve(s , k + 1 , j);
                result = min(result , temp);
            }
        }
        return dp[i][j] = result;
    }
    int minCut(string s) {
        memset(dp , -1 , sizeof(dp));
        return solve(s , 0  , s.length() - 1);
    }
};