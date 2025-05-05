class Solution {
private:
    bool isZero(const vector<int>& counter) {
        for (int i : counter) {
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

        vector<int> counter(26, 0);
        for (int i = 0; i < m; i++) {
            counter[p[i] - 'a']++;
        }

        int i = 0, j = 0;
        while (j < n) {
            counter[s[j] - 'a']--;

            if (j - i + 1 == m) {
                if (isZero(counter)) {
                    result.push_back(i);
                }
                counter[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};