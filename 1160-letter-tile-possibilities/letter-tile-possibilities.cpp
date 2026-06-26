class Solution {
public:
    void backtracking(string& tiles, vector<bool>& used, int& count) {
        for (int i = 0; i < tiles.size(); i++) {

            if (used[i]) continue;

            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            count++;  

            backtracking(tiles, used, count);

            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());

        int count = 0;
        vector<bool> used(tiles.size(), false);

        backtracking(tiles, used, count);

        return count;
    }
};