class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>>result;
          int n = intervals.size();
          sort(intervals.begin() , intervals.end());

          int prev_start = intervals[0][0];
          int prev_end = intervals[0][1];

          for(int i = 1 ; i < n ; i++){
              int curr_start = intervals[i][0];
              int curr_end = intervals[i][1];


              if(curr_start <= prev_end){
                  prev_end = max(curr_end , prev_end);
              }else{
                result.push_back({prev_start , prev_end});
                prev_start = curr_start;
                prev_end = curr_end;
              }
          }
          result.push_back({prev_start , prev_end});
          return result;
    }
};