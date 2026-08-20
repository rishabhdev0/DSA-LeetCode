class Solution {
public:
    int n;
    int dp[1001][3];
    int dp2[1001][3];

    int solve_inc(vector<int>& rating, int idx, int count) {
        if (count == 3) {
            return 1;
        }

        if (idx >= n) {
            return 0;
        }

        if (dp[idx][count] != -1) {
            return dp[idx][count];
        }

        int ans = 0;

        for (int i = idx + 1; i < n; i++) {
            if (rating[i] > rating[idx]) {
                ans += solve_inc(rating, i, count + 1);
            }
        }

        return dp[idx][count] = ans;
    }

    int solve_dec(vector<int>& rating, int idx, int count) {
        if (count == 3) {
            return 1;
        }

        if (idx >= n) {
            return 0;
        }

        if (dp2[idx][count] != -1) {
            return dp2[idx][count];
        }

        int ans = 0;

        for (int i = idx + 1; i < n; i++) {
            if (rating[i] < rating[idx]) {
                ans += solve_dec(rating, i, count + 1);
            }
        }

        return dp2[idx][count] = ans;
    }

    int numTeams(vector<int>& rating) {
        n = rating.size();

        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));

        int answer = 0;

        for (int i = 0; i < n; i++) {
            answer += solve_inc(rating, i, 1);
            answer += solve_dec(rating, i, 1);
        }

        return answer;
    }
};