class Solution {
public:
    int n;
    unordered_set<string> seen;

    int solve(string s, int idx, int count) {
        if(idx >= s.length()) {
            return count;
        }

        int ans = 0;

        for(int i = idx; i < n; i++) {
            string sub = s.substr(idx, i - idx + 1);

            if(seen.count(sub)) {
                continue;
            }

            seen.insert(sub);

            ans = max(ans, solve(s, i + 1, count + 1));

            seen.erase(sub);
        }

        return ans;
    }

    int maxUniqueSplit(string s) {
        n = s.length();
        return solve(s, 0, 0);
    }
};