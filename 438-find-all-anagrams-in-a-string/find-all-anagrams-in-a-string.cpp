class Solution {
private:
    bool isZero(const vector<int>& freq) {
        for (int i : freq) {
            if (i != 0)
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> result;
        if (n < m) return result;

        vector<int> freq(26, 0);
        for (int i = 0; i < m; i++) {
            freq[p[i] - 'a']++;
        }

        int i = 0, j = 0;
        while (j < n) {
            freq[s[j] - 'a']--;

            if (j - i + 1 == m) {
                if (isZero(freq)) {
                    result.push_back(i);
                }
                freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};