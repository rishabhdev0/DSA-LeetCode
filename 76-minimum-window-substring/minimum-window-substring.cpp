class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (n > m) return "";

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }

        int min_window = m + 1;
        int start_index = 0;
        int count_required = n;
        int i = 0, j = 0;

        while (j < m) {
            char curr = s[j];
            if (mp[curr] > 0) {
                count_required--;
            }
            mp[curr]--;

            while (count_required == 0) {
                int curr_window_size = j - i + 1;
                if (min_window > curr_window_size) {
                    min_window = curr_window_size;
                    start_index = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count_required++;
                }
                i++;
            }
            j++;
        }

        return min_window == m + 1 ? "" : s.substr(start_index, min_window);
    }
};
