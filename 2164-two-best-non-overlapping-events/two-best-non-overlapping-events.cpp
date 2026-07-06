class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int maxSum = 0;
        int maxSoFar = 0;

        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            int val = events[i][2];

            while (!pq.empty() && pq.top().first < start) {
                maxSoFar = max(maxSoFar, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, val);
            maxSum = max(maxSum, maxSoFar + val);

            pq.push({end, val});
        }

        return maxSum;
    }
};