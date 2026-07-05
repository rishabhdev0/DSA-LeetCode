class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int, 3>> sortedTask;

        for (int i = 0; i < n; i++) {
            sortedTask.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTask.begin(), sortedTask.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        long long currTime = 0;
        int i = 0;
        vector<int> result;

        while (i < n || !pq.empty()) {
            if (pq.empty() && currTime < sortedTask[i][0]) {
                currTime = sortedTask[i][0];
            }

            while (i < n && sortedTask[i][0] <= currTime) {
                pq.push({sortedTask[i][1], sortedTask[i][2]});
                i++;
            }

            auto top = pq.top();
            pq.pop();

            currTime += top.first;
            result.push_back(top.second);
        }

        return result;
    }
};