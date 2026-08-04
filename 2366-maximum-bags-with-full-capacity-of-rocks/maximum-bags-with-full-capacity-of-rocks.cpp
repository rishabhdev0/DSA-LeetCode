class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();

        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = capacity[i] - rocks[i];
        }

        sort(diff.begin(), diff.end());

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] == 0) {
                result++;
                continue;
            }

            if (additionalRocks >= diff[i]) {
                additionalRocks -= diff[i];
                result++;
            } else {
                break;   // No point checking larger differences.
            }
        }

        return result;
    }
};