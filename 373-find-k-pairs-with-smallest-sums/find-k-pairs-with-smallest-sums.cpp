class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> result;
        if (n == 0 || m == 0 || k == 0) return result;

        priority_queue<p, vector<p>, greater<p>> pq;
        set<pair<int, int>> visited;

        int sum = nums1[0] + nums2[0];

        pq.push({sum, {0, 0}});
        visited.insert({0, 0});

        while (k > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            result.push_back({nums1[i], nums2[j]});
            k--;

            if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                int sum2 = nums1[i + 1] + nums2[j];
                pq.push({sum2, {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < m && visited.find({i, j + 1}) == visited.end()) {
                int sum3 = nums1[i] + nums2[j + 1];
                pq.push({sum3, {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return result;
    }
};