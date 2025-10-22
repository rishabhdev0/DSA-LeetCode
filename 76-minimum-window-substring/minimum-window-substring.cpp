class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (m > n) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int required = m;
        int i = 0, j = 0;
        int min_len = n + 1;
        int start = 0;

        while (j < n) {
            if (freq[s[j]] > 0) {
                required--;
            }
            freq[s[j]]--;

            while (required == 0) {
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    start = i;
                }

                freq[s[i]]++;
                if (freq[s[i]] > 0) {
                    required++;
                }
                i++;
            }
            j++;
        }

        return (min_len == n + 1) ? "" : s.substr(start, min_len);
    }
};