class Solution {
public:
    typedef pair<int, pair<int,int>> P; // (sum, (i,j))

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<P> pq; // max-heap

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = nums1[i] + nums2[j];
                if ((int)pq.size() < k) {
                    pq.push({sum, {i, j}});
                } else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                } else {
                    // if nums2 is sorted, no need to check further j for this i
                    break;
                }
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            P top = pq.top();
            pq.pop();
            int first = top.second.first;
            int second = top.second.second;
            result.push_back({nums1[first], nums2[second]});
        }

        reverse(result.begin(), result.end()); // because max-heap pops largest first
        return result;
    }
};
