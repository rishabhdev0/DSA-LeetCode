class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end(), [](vector<int>& a  , vector<int>& b){
           return a[1] < b[1];
        });

        int removeCount =  0;

        int end = intervals[0][1];

        for(int i = 1 ; i < n ; i++){
           if(end > intervals[i][0]){
             removeCount++;
           }else{
                 end = intervals[i][1];
           }
        }
        return removeCount;
    }
};