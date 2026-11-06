class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int q = queries.size();

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> que;
        for (int k = 0; k < q; k++) {
            que.push_back({queries[k], k});
        }
        sort(que.begin(), que.end());

        vector<int> result(q);
        unordered_map<int, int> freq;

        int i = 0;
        int j = 0;

        for (auto [time, idx] : que) {
            int start = time - x;
            int end = time;

            // add logs with time <= end
            while (j < m && logs[j][1] <= end) {
                int id = logs[j][0];
                freq[id]++;
                j++;
            }

            // remove logs with time < start
            while (i < j && logs[i][1] < start) {
                int id = logs[i][0];
                freq[id]--;
                if (freq[id] == 0) {
                    freq.erase(id);
                }
                i++;
            }

            result[idx] = n - freq.size();
        }
        return result;
    }
};