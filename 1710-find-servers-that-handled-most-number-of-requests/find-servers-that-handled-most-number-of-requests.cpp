class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = load.size();

        set<int> free_server;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy_server;

        vector<int> count(k, 0);

        for (int i = 0; i < k; i++) {
            free_server.insert(i);
        }

        for (int i = 0; i < n; i++) {

            int time = arrival[i];
            int target_server = i % k;

            // Free completed servers
            while (!busy_server.empty() && busy_server.top().first <= time) {
                free_server.insert(busy_server.top().second);
                busy_server.pop();
            }

            // Find next available server
            auto low = free_server.lower_bound(target_server);

            if (low == free_server.end()) {
                low = free_server.begin();
            }

            if (free_server.empty()) {
                continue;
            }

            int server = *low;

            free_server.erase(low);

            int finish_time = time + load[i];

            busy_server.push({finish_time, server});

            count[server]++;
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> result;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                result.push_back(i);
            }
        }

        return result;
    }
};