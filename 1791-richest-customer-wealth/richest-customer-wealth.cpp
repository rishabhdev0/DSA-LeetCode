class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int max_wealth = 0;
        for(int i = 0 ; i < n ; i++){
            int wealth = 0;
            for(int j = 0 ; j < m ; j++){
                wealth += accounts[i][j];
            }
            max_wealth = max(max_wealth , wealth);
        }
        return max_wealth;
    }
};