class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isValid(26, true);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            if (start[ch] == -1) {
                start[ch] = i;
                end[ch] = i;
            } else {
                end[ch] = i;
            }
        }

        // Find valid intervals
        for (int c = 0; c < 26; c++) {
            if (start[c] == -1)
                continue;

            for (int i = start[c]; i <= end[c]; i++) {
                int ch = s[i] - 'a';

            
                if (start[ch] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                end[c] = max(end[c], end[ch]);
            }
        }

        vector<string> result;
        int lastTakenIdx = n;

        for (int i = n - 1; i >= 0; i--) {
            int idx = s[i] - 'a';

            if (!isValid[idx])
                continue;

            if (i == start[idx] && end[idx] < lastTakenIdx) {
                result.push_back(s.substr(i, end[idx] - i + 1));
                lastTakenIdx = i;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};