class Solution {
public:
    typedef pair<char, int> p;

    struct lamda {
        bool operator()(p &p1, p &p2) {
            return p1.second < p2.second; // max-heap
        }
    };

    string frequencySort(string s) {
        priority_queue<p, vector<p>, lamda> pq;
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Push into priority queue
        for (auto &it : freq) {
            pq.push({it.first, it.second});
        }

        string result = "";
        // Build result
        while (!pq.empty()) {
            p temp = pq.top();
            pq.pop();
            result+=string(temp.second, temp.first); 
        }

        return result;
    }
};
