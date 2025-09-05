#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int,int>> P; // (sum, (i, j))

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        int n = nums1.size();
        int m = nums2.size();

        // min-heap of P: use greater<P> to get smallest sum on top
        priority_queue<P, vector<P>, greater<P>> pq;
        set<pair<int,int>> visited; // to avoid duplicates

        // start from (0,0)
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        visited.insert({0, 0});

        // extract up to k pairs
        while (k-- > 0 && !pq.empty()) {
            P temp = pq.top(); pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({ nums1[i], nums2[j] });

            // push (i, j+1)
            if (j + 1 < m && visited.find({i, j+1}) == visited.end()) {
                pq.push({ nums1[i] + nums2[j+1], {i, j+1} });
                visited.insert({i, j+1});
            }

            // push (i+1, j)
            if (i + 1 < n && visited.find({i+1, j}) == visited.end()) {
                pq.push({ nums1[i+1] + nums2[j], {i+1, j} });
                visited.insert({i+1, j});
            }
        }

        return result;
    }
};
