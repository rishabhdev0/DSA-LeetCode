class Solution {
public:
    int dp[21][21];

    int solve(int start, int end, vector<int>& nums) {

        if (start > end)
            return 0;

        if (start == end)
            return nums[start];

        if (dp[start][end] != -1)
            return dp[start][end];

        int take_start = nums[start] +
                         min(solve(start + 2, end, nums),
                             solve(start + 1, end - 1, nums));

        int take_end = nums[end] +
                       min(solve(start + 1, end - 1, nums),
                           solve(start, end - 2, nums));

        return dp[start][end] = max(take_start, take_end);
    }

    bool predictTheWinner(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        int total = accumulate(nums.begin(), nums.end(), 0);

        int player_1 = solve(0, nums.size() - 1, nums);
        int player_2 = total - player_1;

        return player_1 >= player_2;
    }
};