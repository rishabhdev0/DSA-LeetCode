/*
    Genius interval DP.

    Trying to burst balloons from FIRST to LAST is difficult because
    every burst changes the neighbors.

    Instead, think in reverse.

    Assume balloon k is the LAST balloon burst in interval [i...j].

    If k is burst last:
        - Everything left of k has already disappeared.
        - Everything right of k has already disappeared.
        - Therefore the only balloons adjacent to k are
              nums[i-1] and nums[j+1].

    These two boundaries never change while solving [i...j].

    So the coins gained by bursting k last are

        nums[i-1] * nums[k] * nums[j+1]

    After fixing k as the last balloon, the remaining work splits into
    two completely independent subproblems:

        [i ... k-1]
        [k+1 ... j]

    This converts a dynamic-neighbor problem into a fixed-boundary problem,
    which is exactly why interval DP works here.

    Honestly, my ASS would have never solve this problem on my won.
*/

class Solution {
public:
    int dp[301][301];

    int solve(int i, int j, vector<int>& nums) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int max_score = 0;

        // Assume k is the LAST balloon to burst in [i...j]
        for (int k = i; k <= j; k++) {

            int coins =
                nums[i - 1] * nums[k] * nums[j + 1]
                + solve(i, k - 1, nums)
                + solve(k + 1, j, nums);

            max_score = max(max_score, coins);
        }

        return dp[i][j] = max_score;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp, -1, sizeof(dp));

        return solve(1, n, nums);
    }
};