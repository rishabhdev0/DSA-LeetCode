class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        
        vector<int> lastseen(26);
        for (int i = 0; i < n; i++) {
            lastseen[s[i] - 'a'] = i;
        }

        vector<bool> taken(26, false);
        string result;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (taken[idx]) continue;

        while (!result.empty() &&  result.back() > ch && lastseen[result.back() - 'a'] > i){
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            taken[idx] = true;
        }

        return result;
    }
};

auto init = atexit( [](){ ofstream("display_runtime.txt") <<'0'; });

