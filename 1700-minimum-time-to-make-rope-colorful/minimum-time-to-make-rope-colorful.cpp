class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = 0;
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                // Keep the balloon with higher cost, remove the one with lower cost
                totalTime += min(neededTime[i], neededTime[i - 1]);
                // Update the current balloon's time to be the maximum
                // This ensures we always compare with the highest cost balloon ??
                //-> we can keep the highest time needed ballo
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        
        return totalTime;
    }
};