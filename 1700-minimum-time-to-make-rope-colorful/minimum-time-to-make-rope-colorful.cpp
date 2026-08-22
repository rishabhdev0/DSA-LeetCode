class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int min_remove = 0;

        for(int i = 1; i < n; i++) {
            if(colors[i] == colors[i-1]) {
                min_remove += min(neededTime[i], neededTime[i-1]);

                neededTime[i] = max(neededTime[i], neededTime[i-1]);
            }
        }

        return min_remove;
    }
};