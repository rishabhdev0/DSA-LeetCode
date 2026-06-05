class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> pairs;

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = mat[i].size();

            while (start < end) {
                int mid = start + (end - start) / 2;

                if (mat[i][mid] == 1) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }

            pairs.push_back({start, i});
        }

        sort(pairs.begin(), pairs.end());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pairs[i].second);
        }

        return result;
    }
};