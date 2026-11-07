class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();
        vector<int> result(n);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_server;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> busy_server;

        for (int i = 0; i < m; i++) {
            free_server.push({servers[i], i});
        }

        long long time = 0;
        for (int i = 0; i < n; i++) {
            time = max(time, (long long)i);

            // nothing free: jump to the earliest finish time
                           
            if (free_server.empty()) {
            auto [endTime, weight, idx] = busy_server.top();
            time = max(time, (long long)endTime);
            }

            // release all servers done by `time`
            while (!busy_server.empty()) {
             auto [endTime, weight, idx] = busy_server.top();
             if (endTime > time) break;
             busy_server.pop();
            free_server.push({weight, idx});
            }

            auto [weight, idx] = free_server.top();
            free_server.pop();
            result[i] = idx;
            busy_server.push({(int)(time + tasks[i]), weight, idx});
        }
        return result;
    }
};