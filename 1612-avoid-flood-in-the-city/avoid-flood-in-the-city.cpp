class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n, -1);

        unordered_map<int, int> lastRain; // lake -> last rainy day
        set<int> dry; // dry days in sorted order

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dry.insert(i);
                result[i] = 1;
            } else {
                int lake = rains[i];

                if (lastRain.count(lake)) {
                    auto it = dry.upper_bound(lastRain[lake]);

                    if (it == dry.end()) {
                        return {};
                    }

                    int dryDay = *it;
                    result[dryDay] = lake;
                    dry.erase(it);
                }

                lastRain[lake] = i;
            }
        }
        return result;
    }
};