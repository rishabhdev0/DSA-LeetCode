
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int> freq(26, 0);

        for (char ch : p) {
            freq[ch - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> window_freq(26, 0);
        vector<int> result;

        while (j < n) {
            window_freq[s[j] - 'a']++;

            if (j - i + 1 > m) {
                window_freq[s[i] - 'a']--;
                i++;
            }

            if (j - i + 1 == m && window_freq == freq) {
                result.push_back(i);
            }

            j++;
        }

        return result;
    }
};
