#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // Sort by end time 
        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int m = rides.size();
        vector<long long> dp(m + 1, 0);  // dp[i] = best using the first i rides

        for (int i = 1; i <= m; i++) {
            int start = rides[i - 1][0];
            int end   = rides[i - 1][1];
            int tip   = rides[i - 1][2];

            long long profit = end - start + tip;

            int low = 0, high = i - 2;
            int idx = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (rides[mid][1] <= start) {  //not an overlapping rides
                    idx = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            dp[i] = max(dp[i - 1], profit + dp[idx + 1]);
        }

        return dp[m];
    }
};