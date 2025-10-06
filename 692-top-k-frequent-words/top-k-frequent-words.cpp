class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string &word : words) { 
            mp[word]++; 
        }

        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                // If frequencies are equal, compare strings in reverse order
                // so that lexicographically smaller words have higher priority
                return a.second < b.second;
            }
            // Higher frequency has higher priority
            return a.first > b.first;
        };
        
        // Min-heap with custom comparator
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (auto& it : mp) {
            pq.push({it.second, it.first});
            
            // Maintain only k elements in heap
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Build result vector in reverse order
        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        // Reverse to get highest frequency first
        reverse(result.begin(), result.end());
        return result;
    }
};