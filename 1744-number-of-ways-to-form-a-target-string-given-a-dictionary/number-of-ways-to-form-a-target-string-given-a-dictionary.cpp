class Solution { 
public: 
    int dp[1001][1001]; 
    int k; 
    int t; 
    int const mod = 1e9 + 7; 

    int solve(int i, int j, vector<vector<int>>& freq, string& target) { 
        if(i >= t) return 1; 
        if(j >= k) return 0; 

        if(dp[i][j] != -1) {
            return dp[i][j];
        } 

        int not_take = solve(i, j + 1, freq, target) % mod; 

        long long take = 1LL * freq[target[i] - 'a'][j] 
                       * solve(i + 1, j + 1, freq, target) % mod; 

        return dp[i][j] = (not_take + take) % mod; 
    } 

    int numWays(vector<string>& words, string target) { 
        k = words[0].length(); 
        t = target.length(); 
        int n = words.size(); 
        memset(dp, -1, sizeof(dp)); 

        vector<vector<int>> freq(26, vector<int>(k, 0)); 

        for(int i = 0; i < n; i++) { 
            for(int j = 0; j < k; j++) { 
                freq[words[i][j] - 'a'][j]++; 
            } 
        } 

        return solve(0, 0, freq, target); 
    } 
};