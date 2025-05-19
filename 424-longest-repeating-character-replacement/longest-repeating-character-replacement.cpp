class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int max_len = 0;
        int max_count = 0;
        int i = 0, j = 0;

        while (j < n) {
            freq[s[j] - 'A']++;
            max_count = max(max_count, freq[s[j] - 'A']);

            if (j - i + 1 - max_count > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            max_len = max(max_len, j - i + 1);
            j++;
        }

        return max_len;
    }
};
