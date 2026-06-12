class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());

        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = m - 1;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (1LL * spells[i] * potions[mid] >= success) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            result[i] = m - start;
        }

        return result;
    }
};