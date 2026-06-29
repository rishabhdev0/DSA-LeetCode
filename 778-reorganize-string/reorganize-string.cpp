class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
       int n = s.length();
        for (char ch : s) {
            freq[ch]++;
            if(freq[ch] > (n + 1) / 2){
                return "";
            }
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string result = "";

        while (pq.size() > 1) {
            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            result += first.second;
            result += second.second;

            first.first--;
            second.first--;

            if (first.first > 0) {
                pq.push(first);
            }

            if (second.first > 0) {
                pq.push(second);
            }
        }

        if (!pq.empty()) {
           result += pq.top().second;
        }

        return result;
    }
};