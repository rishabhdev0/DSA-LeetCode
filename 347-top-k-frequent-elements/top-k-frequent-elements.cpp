class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Min-heap: stores {frequency, element}
        typedef pair<int, int> p;
        priority_queue<p, vector<p>, greater<p>> pq;

        // Keep only top k frequent elements in heap
        for (auto &it : freq) {
            pq.push({it.second, it.first}); // {frequency, element}
            if (pq.size() > k) {
                pq.pop(); // remove smallest frequency
            }
        }

        // build results
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second); // element
            pq.pop();
        }

        return result;
    }
};
