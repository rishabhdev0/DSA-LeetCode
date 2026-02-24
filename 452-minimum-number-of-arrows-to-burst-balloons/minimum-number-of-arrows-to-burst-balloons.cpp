class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin() , points.end());
        int ArrowNeeded = 1;
        int EndPoint = points[0][1];
        for(int i = 1 ; i < n ; i++){
            if(points[i][0] > EndPoint){
                ArrowNeeded++;
                EndPoint = points[i][1];
            }else{
                // overlapping problem occured;
                EndPoint = min(EndPoint , points[i][1]);
            }
        }
        return ArrowNeeded;
    }
};