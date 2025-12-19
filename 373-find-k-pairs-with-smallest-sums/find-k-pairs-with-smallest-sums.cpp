class Solution {
public:
    typedef pair<int, pair<int, int>> p; // sum -> i, j
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> result;
        priority_queue<p, vector<p>, greater<p>> pq;
    
        set<pair<int, int>> visited;
        
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        visited.insert({0, 0});
        
        while (k > 0 && !pq.empty()) {
            auto current = pq.top();
            pq.pop();
            
            int i = current.second.first;
            int j = current.second.second;
            
            // Add current pair to result
            result.push_back({nums1[i], nums2[j]});
            k--;
            
            // Push next possible pairs
            if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                int sum1 = nums1[i + 1] + nums2[j];
                pq.push({sum1, {i + 1, j}});
                visited.insert({i + 1, j});
            }
            
            if (j + 1 < m && visited.find({i, j + 1}) == visited.end()) {
                int sum2 = nums1[i] + nums2[j + 1];
                pq.push({sum2, {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        
        return result;
    }
};

