class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;

        k = k % total;
        if (k == 0) return grid;

        auto reverseGrid = [&](int i, int j) {
            while (i < j) {
                swap(
                    grid[i / m][i % m],
                    grid[j / m][j % m]
                );

                i++;
                j--;
            }
        };

        reverseGrid(0, total - 1);
        reverseGrid(0, k - 1);
        reverseGrid(k, total - 1);

        return grid;
    }
};