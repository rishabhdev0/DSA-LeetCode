class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int prevMax = neededTime[0];
        int time = 0;
        for(int i = 1 ; i < n ; i++){
            if(colors[i] != colors[i-1]){
                prevMax = 0;
            }
          int  curr = neededTime[i];
            time += min(prevMax , curr);
            prevMax = max(prevMax , curr);
        }
        return time;
    }
};