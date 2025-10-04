#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; ++i) {
            if(!pq.empty() && intervals[i][0] > pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};