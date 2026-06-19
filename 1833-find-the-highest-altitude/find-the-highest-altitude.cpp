class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        vector<int> alti(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            alti[i] = alti[i - 1] + gain[i - 1];
        }

        return *max_element(alti.begin(), alti.end());
    }
};