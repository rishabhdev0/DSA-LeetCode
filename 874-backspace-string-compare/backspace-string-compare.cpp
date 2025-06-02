class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<char> ss;
        vector<char> tt;

        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                if (!ss.empty()) ss.pop_back();
            } else {
                ss.push_back(s[i]);
            }
        }

        for (int j = 0; j < m; j++) {
            if (t[j] == '#') {
                if (!tt.empty()) tt.pop_back();
            } else {
                tt.push_back(t[j]);
            }
        }
        if(ss==tt) return true;
        else return false;
    }
};
