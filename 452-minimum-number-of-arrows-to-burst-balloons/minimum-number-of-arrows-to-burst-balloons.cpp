class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end());
        int arrows = 1;
        int curr_end = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > curr_end) { //  overlap didnt happened
                arrows++;
                curr_end = points[i][1];
            } else {
                curr_end = min(curr_end, points[i][1]); // overlap happened;
            }
        }
        
        return arrows;
    }
};