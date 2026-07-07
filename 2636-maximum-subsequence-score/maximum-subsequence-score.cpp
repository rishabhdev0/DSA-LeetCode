class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> temp;

        for (int i = 0; i < nums1.size(); i++) {
            temp.push_back({nums2[i], nums1[i]});
        }

        sort(temp.rbegin(), temp.rend());

        long long max_score = 0;
        long long sum = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums1.size(); i++) {
            pq.push(temp[i].second);
            sum += temp[i].second;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                max_score = max(max_score, sum * 1LL * temp[i].first);
            }
        }

        return max_score;
    }
};