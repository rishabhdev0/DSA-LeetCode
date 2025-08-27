class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>&lastInterval = result.back();  
            int lastStart = lastInterval[0];    
            int lastEnd   = lastInterval[1];     

            int currentStart = intervals[i][0];  
            int currentEnd   = intervals[i][1]; 

            if (currentStart <= lastEnd) {
                // Overlap exist , then extend the last interval
                lastInterval[1] = max(lastEnd, currentEnd);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
