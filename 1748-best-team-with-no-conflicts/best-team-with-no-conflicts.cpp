
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> score_age(n);

        for(int i = 0; i < n; i++) {
            score_age[i] = {scores[i], ages[i]}; 
        }

        sort(score_age.begin(), score_age.end());

        vector<int> dp(n, 0);
        int ans = 0;

        for(int i = 0; i < n; i++) { 
            dp[i] = score_age[i].first; 

            for(int j = 0; j < i; j++) {
                if(score_age[j].second <= score_age[i].second) {
                    dp[i] = max(dp[i], dp[j] + score_age[i].first);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};