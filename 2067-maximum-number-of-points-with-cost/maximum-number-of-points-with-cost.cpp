class Solution {
public:
    #define ll long long

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<ll> prev(m);
        
        for(int col = 0; col < m; col++) {
            prev[col] = points[0][col];
        }

        for(int row = 1; row < n; row++) {
            vector<ll> curr(m);
            vector<ll> left(m);
            vector<ll> right(m);

            left[0] = prev[0];

            for(int i = 1; i < m; i++) {
                left[i] = max(prev[i], left[i - 1] - 1);
            }

            right[m - 1] = prev[m - 1];

            for(int i = m - 2; i >= 0; i--) {
                right[i] = max(prev[i], right[i + 1] - 1);
            }

            for(int i = 0; i < m; i++) {
                curr[i] = points[row][i] + max(left[i], right[i]);
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};