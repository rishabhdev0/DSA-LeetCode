class Solution {
public:
int count;
void backtracking(string tiles , vector<bool>& used){
    count++;
    for(int i = 0 ; i < tiles.size() ; i++){
        if(used[i] || (i > 0 && tiles[i] == tiles[i-1] && !used[i-1])){
            continue;
        }
        used[i] = true;
        backtracking(tiles , used);
        used[i] = false;
    }
}
    int numTilePossibilities(string tiles) {
        sort(tiles.begin() , tiles.end());
        vector<bool>used(tiles.size() , false);
        count = -1;
        backtracking(tiles , used);
        return count;
    }
};