class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
            if (freq[ch - 'a'] > (n + 1) / 2) {
                return "";
            }
        }

        priority_queue<pair<int, char>> maxHeap;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], char('a' + i)});
            }
        }

        string result = "";

        while (maxHeap.size() > 1) {
            auto first = maxHeap.top();
            maxHeap.pop();

            auto second = maxHeap.top();
            maxHeap.pop();

            result += first.second;
            result += second.second;

            first.first--;
            second.first--;

            if (first.first > 0) {
                maxHeap.push(first);
            }

            if (second.first > 0) {
                maxHeap.push(second);
            }
        }

        if (!maxHeap.empty()) {
            result += maxHeap.top().second;
        }

        return result;
    }
};