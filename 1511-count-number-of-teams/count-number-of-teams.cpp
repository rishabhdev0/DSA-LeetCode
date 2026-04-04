class Solution {
public:
    int dp1[1001][3];
    int dp2[1001][3];

    int solve_inc(vector<int>& rating, int idx, int count){
        if(count == 2) return 1;
        if(idx >= rating.size()) return 0;

        if(dp1[idx][count] != -1){
            return dp1[idx][count];
        }

        int ans = 0;

        for(int j = idx + 1; j < rating.size(); j++){
            if(rating[j] > rating[idx]){
                ans += solve_inc(rating, j, count + 1);
            }
        }

        return dp1[idx][count] = ans;
    }

    int solve_dec(vector<int>& rating, int idx, int count){
        if(count == 2) return 1;
        if(idx >= rating.size()) return 0;

        if(dp2[idx][count] != -1){
            return dp2[idx][count];
        }

        int ans = 0;

        for(int j = idx + 1; j < rating.size(); j++){
            if(rating[j] < rating[idx]){
                ans += solve_dec(rating, j, count + 1);
            }
        }

        return dp2[idx][count] = ans;
    }

    int numTeams(vector<int>& rating) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        int n = rating.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += solve_inc(rating, i, 0);
            ans += solve_dec(rating, i, 0);
        }

        return ans;
    }
};