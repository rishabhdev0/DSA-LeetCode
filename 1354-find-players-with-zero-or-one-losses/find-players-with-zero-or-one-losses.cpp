class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int , int>looses_count;
        set<int>player_count;
        for(int i = 0 ; i <  matches.size() ; i++){
            int winner = matches[i][0];
            int looser = matches[i][1];
            player_count.insert(winner);
            player_count.insert(looser);
            looses_count[looser]++;
        }
        vector<int>zero_looses;
        vector<int>one_looses;
        for(int player : player_count){
            if(looses_count[player] == 0){
                zero_looses.push_back(player);
            }else if(looses_count[player]== 1){
                one_looses.push_back(player);
            }
        }
        return {zero_looses , one_looses};
    }
};