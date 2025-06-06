class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrength; // soldier_count , row_index
        
        for (int i = 0; i < mat.size(); i++) {
            int left = 0, right = mat[i].size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] == 1)
                    left = mid + 1; 
                else
                    right = mid;
            }
            rowStrength.push_back({left, i}); // row_index store the original index
        }
        
        sort(rowStrength.begin(), rowStrength.end()); // sort the soldier count

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(rowStrength[i].second);
        }

        return result;
    }
};
