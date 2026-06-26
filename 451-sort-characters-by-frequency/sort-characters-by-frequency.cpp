class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});   // {frequency, character}
        }

        string result = "";

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int times = top.first;
            char ch = top.second;

            result += string(times, ch);
        }

        return result;
    }
};