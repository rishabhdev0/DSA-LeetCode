class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int n = target.size();
        string result = "";

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // Try to match target[i]
            if (freq[x] > 0) {
                result += target[i];
                freq[x]--;
            }
            else {
                // Cannot match target[i].
                // Try a bigger character at this position.
                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string ans = result;
                        ans += char('a' + c);
                        freq[c]--;

                        // Remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            ans += string(freq[j], char('a' + j));
                        }

                        return ans;
                    }
                }

                // No bigger character possible here.
                // We must backtrack.
                break;
            }
        }

        // Backtrack through the matched prefix only
        for (int i = (int)result.size() - 1; i >= 0; i--) {

            // Put result[i] back into frequency
            freq[result[i] - 'a']++;

            int x = target[i] - 'a';

            // Try smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = result.substr(0, i);
                    ans += char('a' + c);

                    freq[c]--;

                    // Append remaining characters sorted
                    for (int j = 0; j < 26; j++) {
                        ans += string(freq[j], char('a' + j));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};